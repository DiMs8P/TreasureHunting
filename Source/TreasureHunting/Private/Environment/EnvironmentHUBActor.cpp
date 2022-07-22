#include "Environment/EnvironmentHUBActor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "THCharacter.h"

// Sets default values
AEnvironmentHUBActor::AEnvironmentHUBActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnvironmentHUBActor::BeginPlay()
{
    Super::BeginPlay();

    FloorActorSize = GetActorSize(FloorInstance);
    WallActorSize = GetActorSize(WallInstance);
    SpawnFloors();
}

void AEnvironmentHUBActor::SpawnFloors() const
{
    if (!FloorInstance)
        return;
    UWorld* World = GetWorld();
    if (World)
    {
        for (int i = 0; i < MazeWidth; i++)
        {
            for (int j = 0; j < MazeLength; j++)
            {
                const FTransform Transform = FTransform(FRotator::ZeroRotator, FVector(FloorActorSize.X * j, FloorActorSize.Y * i, 0));
                SpawnInstance(Transform, FloorInstance);
            }
        }
    }
}

ATHBaseActor* AEnvironmentHUBActor::SpawnInstance(const FTransform& Transform, const TSubclassOf<ATHBaseActor>& Actor) const
{
    UWorld* World = GetWorld();
    const auto Instance = World->SpawnActorDeferred<ATHBaseActor>(Actor, Transform);
    Instance->FinishSpawning(Transform);
    return Instance;
}

FVector AEnvironmentHUBActor::GetActorSize(TSubclassOf<ATHBaseActor>& Actor) const
{
    UWorld* World = GetWorld();
    if (!World)
        return FVector::ZeroVector;

    const auto Instance = World->SpawnActor<ATHBaseActor>(Actor, FTransform(FRotator::ZeroRotator, FVector(2000, 2000, 2000)));

    if (!Instance)
        return FVector::ZeroVector;

    const FVector InstanceSize = Instance->GetActorSize();
    Instance->Destroy();
    return InstanceSize;
}

void AEnvironmentHUBActor::ChangeActorPosition(const FVector& NewPosition)
{
    const auto Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    const auto Player = Controller->K2_GetPawn();
    Player->SetActorLocation(NewPosition);
}

void AEnvironmentHUBActor::GenerateMaze()
{
    for (int i = 0; i < Actors.Num(); i++)
        Actors[i]->Destroy();
    Actors.Empty();

    int32 StartPointX = MakeRandomOddNumber(0, MazeLength);
    int32 StartPointY = MakeRandomOddNumber(0, MazeWidth);

    FVector NewActorPosition(FloorActorSize.X * StartPointX, FloorActorSize.Y * StartPointY, 500);
    ChangeActorPosition(NewActorPosition);
    TArray<int32> InnerMap;

    GetCoordsMap(InnerMap, MazeWidth, MazeLength);
    BuildLabirinth(InnerMap);
}

void AEnvironmentHUBActor::BuildLabirinth(TArray<int32>& InnerMap)
{
    for (int i = 0; i < InnerMap.Num(); i++)
    {
        int32 CurLen = i / MazeWidth;
        int32 CurWidth = i % MazeWidth;
        if (InnerMap[i] == WALL)
        {
            FTransform Transform = FTransform(FRotator::ZeroRotator,
                FVector(CurLen * FloorActorSize.X, FloorActorSize.Y * CurWidth, FloorActorSize.Z / 2 + WallActorSize.Z / 2));
            Actors.Add(SpawnInstance(Transform, WallInstance));
            UE_LOG(LogTemp, Display, TEXT("Num actors = %i"), Actors.Num());
        }
    }
}

int AEnvironmentHUBActor::MakeRandomOddNumber(int32 Min, int32 Max)
{
    Min = Min / 2;
    Max = Max / 2 - 1;
    int32 RandOddInt = FMath::RandRange(Min, Max);
    RandOddInt = (RandOddInt * 2) + 1;
    return RandOddInt;
}

void AEnvironmentHUBActor::GetCoordsMap(TArray<int32>& Map, const int32& Width, const int32& Lenght)
{
    FillStartCoordsMap(Map, Lenght, Width);

    FPoint StartCell = {1, 1};

    UE_LOG(LogTemp, Display, TEXT("StartPoint = %i %i"), StartCell.X, StartCell.Y);
    FPoint CurrentCell = StartCell;
    TArray<FPoint> Neighbours;
    TArray<FPoint> Visited;
    Map[Width * StartCell.X + StartCell.Y] = VISITED;
    do
    {
        GetNeighbours(Lenght, Width, Map, CurrentCell, Neighbours);

        if (Neighbours.Num() == 0)
        {
            CurrentCell = Visited.Top();
            Visited.Pop();
        }
        else
        {
            Visited.Add(CurrentCell);
            CurrentCell = Neighbours[(rand() % Neighbours.Num())];
            Neighbours.Empty();
            Map[Width * CurrentCell.Y + CurrentCell.X] = VISITED;
            MakeHole(Width, (Visited.Top().X + CurrentCell.X) / 2, (Visited.Top().Y + CurrentCell.Y) / 2, Map);
        }

    } while (Visited.Num());
}
void AEnvironmentHUBActor::GetNeighbours(
    const int32 Height, const int32 Width, const TArray<int32>& Map, const FPoint StartPoint, TArray<FPoint>& Neighbors)
{
    FPoint Temp;

    if (StartPoint.X + 2 < Width && Map[Width * StartPoint.Y + (StartPoint.X + 2)] != 2)
    {
        Temp = {StartPoint.X + 2, StartPoint.Y};
        Neighbors.Add(Temp);
    }

    if (StartPoint.X - 2 >= 0 && Map[Width * StartPoint.Y + (StartPoint.X - 2)] != 2)
    {
        Temp = {StartPoint.X - 2, StartPoint.Y};
        Neighbors.Add(Temp);
    }
    if (StartPoint.Y + 2 < Height && Map[Width * (StartPoint.Y + 2) + StartPoint.X] != 2)
    {
        Temp = {StartPoint.X, StartPoint.Y + 2};
        Neighbors.Add(Temp);
    }
    if (StartPoint.Y - 2 >= 0 && Map[Width * (StartPoint.Y - 2) + StartPoint.X] != 2)
    {
        Temp = {StartPoint.X, StartPoint.Y - 2};
        Neighbors.Add(Temp);
    }
}

void AEnvironmentHUBActor::MakeHole(const int32 Width, const int32 X, const int32 Y, TArray<int>& Maze)
{
    Maze[Width * Y + X] = CELL;
}

void AEnvironmentHUBActor::FillStartCoordsMap(TArray<int32>& Map, const int32& Lenght, const int32& Width)
{

    for (int i = 0; i < Lenght; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            if ((i % 2 != 0 && j % 2 != 0) && (i < Lenght - 1 && j < Width - 1))
                Map.Add(CELL);
            else
                Map.Add(WALL);
        }
    }
}
//void AEnvironmentHUBActor::DebugPrintMap(TArray<int32>& Map) const
//{
//    for (int i = 0; i < Map.Num(); i++)
//    {
//        UE_LOG(LogTemp, Display, TEXT("%i "), Map[i]);
//    }
//}