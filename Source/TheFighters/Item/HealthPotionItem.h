#pragma once

#include "CoreMinimal.h"
#include "Item/ItemBase.h"
#include "HealthPotionItem.generated.h"

UCLASS()
class THEFIGHTERS_API AHealthPotionItem : public AItemBase
{
    GENERATED_BODY()

public:
    AHealthPotionItem();

protected:
    virtual void BeginPlay() override;
};