// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Gun.generated.h"

UCLASS()
class CPP_TMP_9_API ACPP_Gun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Gun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void Fire(class TSubclassOf<ACPP_Bullet> bulletOrigin);

	//�Ʒ� �Լ��� ĳ���� ������ �� �ѹ��� ����, ���ӿ��� �� ���� �; �׳� U�Լ� �ƴ�
	//=���� �ʿ伺�� ����� U�Լ��� ������ �Ѵ�
	void EquipTo(AActor* parent);
};
