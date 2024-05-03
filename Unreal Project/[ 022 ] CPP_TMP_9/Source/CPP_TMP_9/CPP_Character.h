// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Character.generated.h"

UCLASS()
class CPP_TMP_9_API ACPP_Character : public ACharacter
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

	// �𸮾󿡼� �ڵ�� ������ �ο��ϴ� 2���� ����
	// 1. �̺�Ʈ�� �������� �� (On~~~ �ڵ尡 ������ ���ۿ� ���� ����� �ο��Ѵ�) : ��ȿ���� (�𸮾󿡼��� ��ħ�� �ƴ�)
	// 2. �� ���ۿ� ���� �ൿ�� �Լ��� �̸� ���صΰ�, �Է� �׼ǿ� ���ε��Ѵ� (�̺�Ʈ�� �Լ� ������ �Ҵ�) : ȿ���� (�𸮾� ���� ��ħ)
	//    ���� �ִ� SetupPlayerInputComponent �Լ��� �� 2�� ������ ���� �ϱ� ���ؼ� ������� ��.

	// -> ���� ���⼭�� �ൿ �Լ��� ����� �Է� �׼ǿ� ���ε�

	// �̵� �Լ�
	UFUNCTION() // �𸮾�� �Լ���� �ǹ��� (+�ΰ� �ɼ� ���� ������) ��ũ��
				// �� �ʿ����� ������, ��Ģ������ �տ� �ٿ��ִ� ���� ��ħ�̶�� �Ѵ�
				// ������ ���, UPROPERTY()��� ��ũ�� ���
	void MoveForward(float value);
	//UFUNCTION() void MoveRight(float value); // <- �̷��� �ص� �Ǵµ� ���ü��� ����
	UFUNCTION()
	void MoveRight(float value);

	// �þ� �Լ�
	UFUNCTION()
	void LookUp(float value);
	UFUNCTION()
	void LookRight(float value);

	// �׼� ���� �Լ�
	UFUNCTION()
	void JumpAction(); // <- ĳ���Ϳ� Jump��� �Լ��� ���� �ְ�, �������̵� �Ұ� = �ٸ� �̸� �ʿ�
	UFUNCTION()
	void ShootAction();

};
