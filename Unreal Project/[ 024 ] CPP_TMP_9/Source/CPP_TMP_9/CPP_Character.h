// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//�÷��̾� ĳ���Ϳ��� ���� �Է��� �ο�
#include "EnhancedInputComponent.h" // ���� �Է��� �����ϴ� ������Ʈ ���
#include "EnhancedInputSubsystems.h" //���� �Է��� ��Ʈ�ѷ� ���̿��� �߰��ϴ� ����ý���
#include "InputActionValue.h"       // �Է¿� ���� ������ ��� �ް� ȣ������ִ� ���� ���

//�Ѱ� �Ѿ�
#include "CPP_Gun.h"
#include "CPP_Bullet.h"

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

	//�߻縦 ���� �ʿ��� ����

	// 1.�Ѿ�
	// 2.�Ѿ��� ���� ��ġ
	// 3. (�ɼ�) ���� ��� ��ü (�ڽ��̾ ���������, �׼� ���� Ŭ������ ������ �� ����)


	//�Ѿ�
	//UPROPERTY() // UPROPERTY : �����Ͱ� �𸮾󿡼� ���Ǵ� �뵵���� ǥ��
	UPROPERTY(EditAnywhere, Category = Gun, BlueprintReadWrite)
	TSubclassOf<ACPP_Bullet> bullet; // �Ѿ��� ���� Ŭ���� (�Ļ��� ����)
	
	// UPROPERTY �ɼ�
	//EditAnywhere : �������̽� ���� ���ɽ�, ���� ��𼭵� �� �����͸� ������ �� �ִٴ� ��
	//Category : �� ������ �����Ϳ��� � �з������� ���еǴ����� �����ϴ� ��
	//           ���⿡ �̸��� �ָ� �����Ͱ� �� ������ �ش� �׷����� ������ ���ְ�
	//           ���� �������Ʈ���� ����ÿ��� ������ �ش� �׷쿡�� ǥ�����ش�
	//           ī�װ� �̸��� �ִ� �з����� ���ų�, ���� ���� �� �ִ�
	//           * �ִ� �̸��� ���� ���� �з��� ����. ������ �̸��� ���� �������� ���� �����
	//           ** Ȥ�� �з����� �����Ͱ� �������� ���ϸ�, Gameplay�� ī�װ� ������ ��
	//BlueprintReadWrite : �� ������ �������Ʈ���� �����Ű��,
	//                     �������Ʈ â �ȿ��� ���� �����ϰ� ������ ��

	//��
	UPROPERTY(EditAnywhere, Category = Gun, BlueprintReadWrite)
	TSubclassOf<ACPP_Gun> gunOrigin; //���� ����

	UPROPERTY() // ���ʿ��� �ɼ� ������ ����ȭ
	ACPP_Gun* gun; // ������ ���� ������� ��¥ ��

	//�� ���� �� ������ ��ġ ���� (��ü���� ���� �����Ϳ��� �� ������)
	UPROPERTY(EditAnywhere, Category = Gun, BlueprintReadWrite)
	FVector gunLocation;
	//FVector : ���͸� �Ҽ��� ǥ���ߴٴ� �𸮾�� ǥ�� (F ���λ� = float)
	// -> �𸮾󿡼��� Ŭ������, �Լ���, ������ �տ� �̷��� �ʿ信 ����
	//    �����̳� �뵵�� �����ϴ� ���λ縦 ���̰� �Ѵ� (�����սô�!)


	//-----���� �Է°� IMC ����-----

	// �Է� �׼� �����͸� �޾Ƴ��� ���� ���� ����
	// (���� �����ʹ� �����Ϳ��� ����� -�������Ʈ��...-)

	//->������ �������Ʈ�� �޾ƾ� �ϹǷ� ���� ������ ���·�

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
		UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
		UInputAction* Input_Move;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
		UInputAction* Input_Look;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
		UInputAction* Input_Jump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
		UInputAction* Input_Shoot;


	// �Է��� ������ �������� ��� �Լ� (���� ���� �Է¿��� ���� ���� �� �޵���)

	UFUNCTION()
		void EI_Move(const FInputActionValue& value);
	// * const FInputActionValue& : FInputActionValue�� �Է¿��� �����ϴ� ��� ������ ���� ����ü
	//                              ���� �Է� �������̽������� �� ���� ����� �޾Ƽ� ó���ϵ��� ����

	UFUNCTION()
		void EI_Look(const FInputActionValue& value);

	UFUNCTION()
		void EI_Shoot(const FInputActionValue& value);

	// ������.... �׳� ĳ���� ���� ������ �մϴ�....
};
