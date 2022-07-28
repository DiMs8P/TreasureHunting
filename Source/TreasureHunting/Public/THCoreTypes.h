#pragma once

#include "THCoreTypes.generated.h"

USTRUCT()
struct FPoint
{
    GENERATED_USTRUCT_BODY()
public:
    int32 X;
    int32 Y;
    FPoint()
    {
        this->X = 0;
        this->Y = 0;
    }
    FPoint(int32 X, int32 Y)
    {
        this->X = X;
        this->Y = Y;
    }
};

UENUM()
enum ECellType
{
    FREE,
    BLOCK,
    VISITED
};

UENUM()
enum EEnvType
{
    FLOOR,
    WALL,
    CHEST
};