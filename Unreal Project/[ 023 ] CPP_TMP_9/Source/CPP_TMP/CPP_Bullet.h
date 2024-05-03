// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
//#include "Engine/Engine.h" // <- �ٷ� ���� �߻� x, �� ���� ��ħ�� �����
//#include "Engine.h" // <- �ٷ� ���� �߻�
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Bullet.generated.h"

UCLASS()
class CPP_TMP_API ACPP_Bullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Bullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//�Ѿ��� �����Ӱ� ���� �Լ���

	UFUNCTION() // �߻�� ���� �̵��ϱ�
		void Fire(FVector direction);

	UFUNCTION() // ���߿� ����� ��Ʈ�� �̺�Ʈ �̸� ����
		void OnHit(UPrimitiveComponent* hitComp,
			AActor* otherActor, UPrimitiveComponent* otherComp,
			FVector normalImpulse,
			const FHitResult& Hit);

	// �Ѿ��� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* movement;

	// �Ѿ��� �����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* collision;
};
