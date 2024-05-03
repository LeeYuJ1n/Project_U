// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; // ƽ(������Ʈ) ��� ����

}

// Called when the game starts or when spawned
void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//���� �Ҵ�(�Է� �׼ǿ� �Լ� ���ε�)

	//�Է� �̺�Ʈ�� ���� �Լ� ���� ������ �ڵ����� ����
	//BindAxis : �� ���� ���ε�
	//�Ű����� : �̸� - �Է� �׼��� �̸�
	//          this - �Լ� ������ ��ü. �������Ʈ���� self���� ���� ���⼭�� this
	//          �Լ��� ������ - ���ε��Ϸ��� �Լ�

	PlayerInputComponent->BindAxis
	("Legacy_MoveForward", this, &ACPP_Character::MoveForward);
	PlayerInputComponent->BindAxis
	("Legacy_MoveRight", this, &ACPP_Character::MoveRight);

	PlayerInputComponent->BindAxis
	("Legacy_LookUp", this, &ACPP_Character::LookUp);
	PlayerInputComponent->BindAxis
	("Legacy_LookRight", this, &ACPP_Character::LookRight);

	// BindAction : ������ ���� �Է¿� �Լ��� �Ҵ��ϴ� �Լ�
	// �Ű����� �� ��° IE_Pressed : Ű�� ������ �� �����Ѵٴ� ��
	//                 IE_Released : Ű�� ������ �����Ѵ�

	PlayerInputComponent->BindAction
	("Legacy_Jump", IE_Pressed, this, &ACPP_Character::JumpAction);
	PlayerInputComponent->BindAction
	("Legacy_Shoot", IE_Pressed, this, &ACPP_Character::ShootAction);
}

void ACPP_Character::MoveForward(float value)
{
	// ���� ���͸� ���ϰ�, �̿� ���� �÷��̾ ������ ������
	FVector dir = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	//FVector : DX�� ���� ����. F�� ���� ���ڰ� �Ҽ���� �ǹ�
	//FRotationMatrix : DX�� ���� ���. F�� �Ҽ��� ��, Rotation�� �� ��� ȸ�������� ���� �ִٴ� ǥ��
	//Controller : ĳ���Ͱ� ���� ���� �ִ� ���۱���=��Ʈ�ѷ�
	//GetControlRotation : �� ��Ʈ�ѷ��� ���� �ִ� ȸ�� ����(=ī�޶� �پ��� ���, �þ�)
	//GetScaledAxis : ���� �־��� ȸ�������� �������� �� ������ �и�
	//EAxis::X : Enum���� ������� �� ��� �߿��� X��. ĳ������ ���, X���� ������ ����
	// ����... �� �ڵ带 ��� ������ : "���� ���� �ִ� ���� �������� ���� �ุ ���ͷ� ���ϱ�" = ���� ����
	// �������Ʈ�� Get Control Rotation > Get Forward Vector ���� �Ȱ��� �ǹ�

	// �̵� �Է� �߰� �Լ��� ȣ���ؼ� �÷��̾ ������ �̵� ����
	// -> C++ �ڵ忡���� �� �Լ��� ȣ�� ��ü�� (�̵� ������Ʈ�� ��Ʈ�ѷ��� �ƴ϶�)
	//    ���̶�� ���� ����
	APawn::AddMovementInput(dir, value);
}

void ACPP_Character::MoveRight(float value)
{
	FVector dir = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	APawn::AddMovementInput(dir, value);
}

void ACPP_Character::LookUp(float value)
{
	APawn::AddControllerPitchInput(value);
}

void ACPP_Character::LookRight(float value)
{
	APawn::AddControllerYawInput(value);
}

void ACPP_Character::JumpAction()
{
	ACharacter::Jump(); //ĳ���� �θ� Ŭ������ ���� ���� �״�� ����
}

void ACPP_Character::ShootAction()
{
}

