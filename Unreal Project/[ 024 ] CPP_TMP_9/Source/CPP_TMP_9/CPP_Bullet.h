// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Engine.h" // <- ��ü ���� �Ѱ� ���. ���� ���� �ʴ´� (���� �����Ͱ� �� �Ѵ�)
//#include "Engine/Engine.h" //<-���ʹ� �ٸ� ������ ���� ��ɾ� ���. ���� ���� ���� �ʴ´�
							 // (������ ������ ������, ���� ������ ������ �����)

// ���� 4.25 ���ĺ��� �� ������� ���� ���ϰ� �����ϴ� ����
// 1. ������ ���� ���� (������ ���� �ǵ� �ʹ� ���� ���ٱ��� �������� �� �𸮾� �����ڵ��� �Ⱦ��Ѵ�)
// 2. ������ �ð��� ���� (���� �ɸ���)
// 3. ���� �ð��� ���� (������ ���̴� ������, ��·�� ���� �ɸ���)
// -> ������ ��ħ�� �� �ڱⰡ ������ Ŭ������ �ش��ϴ� ����� ��Ŭ����϶�� �Ѵ� (IWYU)
// -> �����̳� �ߵ� �����̶�� Engine/Engine.h������ �Ƹ� �ᵵ ����������...
//    �ᱹ ���带 �������� �ϴ� �����̶�� �̰����� �������� �� ����� ���� Ȯ���� ���� �� �ִ�

// ���� ��ħ�� ���Ѽ� �� Ŭ�������� �𸮾��� �߰� ����� ����Ϸ���?
// -> ���۷��� ������, Ȥ�� Ŭ���� �˻�

#include "GameFramework/ProjectileMovementComponent.h" // �߻�ü �̵� ������Ʈ
#include "Components/SphereComponent.h" // ��ü ��� ������Ʈ

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Bullet.generated.h"

UCLASS()
class CPP_TMP_9_API ACPP_Bullet : public AActor
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

	// �����Ӱ� ���� �Լ�

	UFUNCTION()
		void Fire(FVector direction);

	UFUNCTION()
		void OnHit //ON~~~ : �̺�Ʈ �߻� �ÿ� ó���� �Լ���� �ǹ̸� �۸� ��´�
		(UPrimitiveComponent* hitComp, //�ε�ģ ����
			AActor* otherActor, //�ε�ģ ǥ��
			UPrimitiveComponent* otherComp, // ǥ������ �ε�ģ ����
			FVector normalImpulse, //��Ʈ �ÿ� �߻��� �ݹ� ����(=�ε�ģ ��ġ�� ����)
			const FHitResult& Hit //��Ÿ �ε�ģ ����� ����� ����ü
		);

	// �Ѿ��� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* movement;

	// �Ѿ��� ����� (�浹 ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* collision;
};
