#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "THCoreTypes.h"
#include "THEnvironmentHubActor.generated.h"

class ATHBaseEnvironmentHUBActor;

UCLASS()
class TREASUREHUNTING_API ATHEnvironmentHubActor : public AActor
{
    GENERATED_BODY()

public:
    ATHEnvironmentHubActor();

    void InitMazeFloor();
    void GenerateMaze();
    void SpawnChestInRandPos();


    void SetActorRandPosionBasedOnFloorSize() const;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
    TArray<TSubclassOf<ATHBaseEnvironmentHUBActor>> HUBActors;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (ClampMin = "3", ClampMax = "101"))
    int32 MazeLength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (ClampMin = "5", ClampMax = "101"))
    int32 MazeWidth;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Data")
    int32 EnvHUBNum = 3;

private:
    UPROPERTY()
    TArray<ATHBaseEnvironmentHUBActor*> HubActorsInstances;

    template <typename T> T* GetHubActor(const int32 ID)
    {

        const auto HubActor = Cast<T>(HubActorsInstances[ID]);
        if (!HubActor)
        {
            UE_LOG(LogTemp, Error, TEXT("Can't find hub actor, it's ID: %i"), ID);
            checkNoEntry();
        }
        return HubActor;
    }

    int32 MakeRandomOddNumber(int32 Min, int32 Max) const;

    FVector FloorSize;
    
};
