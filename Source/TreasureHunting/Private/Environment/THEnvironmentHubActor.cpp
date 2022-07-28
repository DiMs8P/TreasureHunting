#include "Environment/THEnvironmentHubActor.h"
#include "THBaseEnvironmentHUBActor.h"
#include "Kismet/GameplayStatics.h"
#include "THPlayerController.h"
#include "THFloorHub.h"
#include "THTrophyHub.h"
#include "THWallHub.h"

ATHEnvironmentHubActor::ATHEnvironmentHubActor() {}

void ATHEnvironmentHubActor::BeginPlay()
{
    Super::BeginPlay();

    if (MazeWidth % 2 == 0 || MazeLength % 2 == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("Maze Width and Length must be odd!"))
        checkNoEntry();
    }

    checkf(HUBActors.Num() == EnvHUBNum, TEXT("You forgot to set enough HUB actors, you need %i actors"), EnvHUBNum);

    UWorld* World = GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't get a World pointer!"))
        checkNoEntry();
    }

    for (int i = 0; i < HUBActors.Num(); i++)
    {
        const auto HubInstance =
            World->SpawnActorDeferred<ATHBaseEnvironmentHUBActor>(HUBActors[i], FTransform(FRotator::ZeroRotator, FVector(0, 0, 0)));
        HubInstance->FinishSpawning(FTransform(FRotator::ZeroRotator, FVector(0, 0, 0)));
        HubActorsInstances.Add(HubInstance);
    }

    for (const auto HUBActor : HubActorsInstances)
    {
        if (!HUBActor)
            continue;
        HUBActor->Init(MazeWidth, MazeLength);
    }

    InitMazeFloor();
    GenerateMaze();
}

void ATHEnvironmentHubActor::InitMazeFloor()
{
    const auto FloorHubActor = GetHubActor<ATHFloorHub>(EEnvType::FLOOR);

    FloorHubActor->InitMazeFloor();
    FloorSize = FloorHubActor->GetActorSize();
}

void ATHEnvironmentHubActor::GenerateMaze()
{
    const auto WallHubActor = GetHubActor<ATHWallHub>(EEnvType::WALL);

    WallHubActor->SetFloorSize(HubActorsInstances[EEnvType::FLOOR]->GetActorSize());
    WallHubActor->GenerateMaze();
    SetActorRandPosionBasedOnFloorSize();
    SpawnChestInRandPos();
}

void ATHEnvironmentHubActor::SpawnChestInRandPos()
{
    const auto ChestHubActor = GetHubActor<ATHTrophyHub>(EEnvType::CHEST);

    FVector ActorSize = ChestHubActor->GetActorSize();
    int32 StartPointX = MakeRandomOddNumber(0, MazeLength);
    int32 StartPointY = MakeRandomOddNumber(0, MazeWidth);

    FVector NewActorPosition(FloorSize.X * StartPointX, FloorSize.Y * StartPointY, FloorSize.Z / 2);

    const auto Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    const auto CurController = Cast<ATHPlayerController>(Controller);

    const auto CurPlayer = CurController->K2_GetPawn();

    while (NewActorPosition.X == CurPlayer->GetActorLocation().X && NewActorPosition.Y == CurPlayer->GetActorLocation().Y)
    {
        StartPointX = MakeRandomOddNumber(0, MazeLength);
        StartPointY = MakeRandomOddNumber(0, MazeWidth);
        NewActorPosition = FVector(FloorSize.X * StartPointX, FloorSize.Y * StartPointY, FloorSize.Z / 2);
    }

    ChestHubActor->SpawnChest(FTransform(FRotator::ZeroRotator, NewActorPosition));
}

void ATHEnvironmentHubActor::SetActorRandPosionBasedOnFloorSize() const
{
    int32 StartPointX = MakeRandomOddNumber(0, MazeLength);
    int32 StartPointY = MakeRandomOddNumber(0, MazeWidth);

    FVector NewActorPosition(FloorSize.X * StartPointX, FloorSize.Y * StartPointY, 500);

    const auto Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    const auto CurController = Cast<ATHPlayerController>(Controller);

    const auto CurPlayer = CurController->K2_GetPawn();
    if (!CurPlayer)
    {
        return;
    }
    CurPlayer->SetActorLocation(NewActorPosition);
}

int32 ATHEnvironmentHubActor::MakeRandomOddNumber(int32 Min, int32 Max) const
{
    int32 TempMin = Min / 2;
    int32 TempMax = Max / 2 - 1;
    int32 RandOddInt = FMath::RandRange(TempMin, TempMax);
    RandOddInt = (RandOddInt * 2) + 1;
    return RandOddInt;
}
