#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "THBaseEnvironmentHUBActor.generated.h"

class ATHBaseActor;

UCLASS()
class TREASUREHUNTING_API ATHBaseEnvironmentHUBActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATHBaseEnvironmentHUBActor();

	FVector GetActorSize() { return ControlledActorSize; }

	virtual void Init(int32 MazeWidth, int32 MazeLength);

protected:
	virtual void BeginPlay() override;

	virtual ATHBaseActor* SpawnInstance(const FTransform& Transform) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
    TSubclassOf<ATHBaseActor> ControlledActor;

	FVector ControlledActorSize;

	int32 MazeWidth;
    int32 MazeLength;
};
