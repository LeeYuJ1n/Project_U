// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPP_Gun.h"
#include "CPP_Bullet.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Character.generated.h"

UCLASS()
class CPP_TMP_API ACPP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// �� �Լ��� ���۽� ������ �Ҵ��� ���� �Լ�
	// �׸��� �Ʒ����� �ش� ���� �Ҵ翡 ����� ���� �ൿ �Լ�

	// �̵�

	UFUNCTION() // �����Ϳ����� ����ϴ� �𸮾� �Լ����� ǥ�� (+���ϸ� �߰� �ɼǵ�)
	void MoveForward(float value);
	
	UFUNCTION()
	void MoveRight(float value);
	
	UFUNCTION()
	void LookUp(float value);
	
	UFUNCTION()
	void LookRight(float value);

	// ������ �߻�

	UFUNCTION()
	void JumpAction();

	UFUNCTION()
	void ShootAction();

	// ��⿡ ����ϱ� ���� �ΰ� ������ (�Ѿ˰� �� ��� �׼� Ŭ����)
	//UPROPERTY() //�𸮾󿡼� ���� ���������� ��Ÿ���� ��ũ�� + �ΰ� �ɼ� ����
	UPROPERTY(EditAnywhere, Category = Gun, BlueprintReadWrite)
	FVector gunLocation; // FVector : �𸮾� ���̺귯�� �� ���� ǥ��

	//ACPP_Bullet bullet; // C++ �ȿ��� Ŭ���� �ȿ��� ���� ������ ����
					      // �𸮾󿡼� Ŭ������ ������ ������� �ѹ� �� ���������
	UPROPERTY(EditAnywhere, Category = Projectile, BlueprintReadWrite)
	TSubclassOf<class ACPP_Bullet> bullet;
	// �ܼ� Ŭ������ �ƴ϶� Ŭ������ �����ϴ� ������ �� ��ӵ� Ŭ�������� ������� ��Ī

	// * �� UPROPERTY���� ����� ��ũ�� �� �ΰ� �ɼ�
	//   -> �ش� �����Ͱ� �������Ʈȭ�Ǿ��� �� ��� ��޵����� ������ ��

	// EditAnyWhere : ���� ��𼭵� (���̸�) ������ �� �ִٴ� ��
	// BlueprintReadWrite : �������Ʈ ȯ�� ������ �� �����Ͱ� ����ǰ�,
	//                      ���� ������ �� �ִٴ� ��
	// Category = �������Ʈ ȯ�濡�� �����Ͱ� ��� �з�ĭ�� �������� ���ϴ� ��
	//            �����Ϳ� �־��� �з����� ���ų�, ���Ƿ� ���ο� �з��� ���� �� �ִ�
	//            Ȥ�� �� ������ �з����� ������, Gameplay�� ī�װ��� ���ϸ� �ȴ�
};
