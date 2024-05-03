// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//ĳ���Ͱ� ����������� Ȯ�� (����Ʈ ��Ʈ�� = ��ũ�� �޽���)
	if (GEngine) // ��� ��� ������ ������ġ��
		GEngine->AddOnScreenDebugMessage
		(-1, 10.0f, FColor::Red, TEXT("Character Spawned!"));

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

	//������ �Ҵ� : �̺�Ʈ�� �Լ��� ���ε��ϵ��� �ϸ� �ȴ�

	//�̵�
	PlayerInputComponent->BindAxis("Legacy_MoveForward", this, &ACPP_Character::MoveForward);
	PlayerInputComponent->BindAxis("Legacy_MoveRight", this, &ACPP_Character::MoveRight);

	//�þ�
	PlayerInputComponent->BindAxis("Legacy_LookUp", this, &ACPP_Character::LookUp);
	PlayerInputComponent->BindAxis("Legacy_LookRight", this, &ACPP_Character::LookRight);

	//�׼�(������ �߻�)
	PlayerInputComponent->BindAction("Legacy_Jump", IE_Pressed, this, &ACPP_Character::JumpAction);
	PlayerInputComponent->BindAction("Legacy_Shoot", IE_Pressed, this, &ACPP_Character::ShootAction);
}

void ACPP_Character::MoveForward(float value)
{
	FVector dir = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
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
	// ������ �׳� ĳ���� ��� �״�� �Ẹ���
	ACharacter::Jump();
}

void ACPP_Character::ShootAction()
{
	// �� ���

	if (bullet)
		// <- �ܼ��� �ִ°��� �ƴ϶�, �𸮾󿡼� �ش� ������ ���� �����Ͱ� �ִ��� ����
	{

		// �Ѿ� �߻� ���� ����� (���� ��ġ�� ���� ����ؼ�)

		// �� ��ġ ã��

		FVector location = GetActorLocation();
		FRotator rotation = GetActorRotation();
		
		// (�ɼ�) �� �ٸ� ���� ��ġ : 1��Ī�� �� ���
		FVector FPLocation;
		FRotator FPRotation;

		GetActorEyesViewPoint(FPLocation, FPRotation);
		// ���͸� ���� ���� ��Ʈ�ѷ�,
		// Ȥ�� ī�޶� ������ �ش� ī�޶��� ����Ʈ ��ġ�� ȸ���� �Ű������� �����ϴ� �Լ�

		// ������ ã�� �� ��ġ Ȥ�� �þ� ��ġ�� �������� �ٽ� �߻� ��ġ�� ������ ���

		// ���� ��ġ, ���� ������ ��������, ���� ���͸�ŭ ��� �̵��� �� ��ġ
		FVector shootLocation = FPLocation + FTransform(rotation).TransformVector(gunLocation);
		FRotator shootRotation = FPRotation; // �߻� ������ ���� ������ �״�� ���� (������ ������ 2����)

		// �Ѿ� �����
		// GetWorld()->SpawnActor() : �⺻��

		UWorld* world = GetWorld(); // ���带 �̸� �����ͷ� �ޱ�
		if (world) // isValid ��Ģ�� �����غ��� (������ ���ǹ��� ����Ǵ� �������� ������ ���ʹ� ������ ���ۿ� ������...)
		{
			//���Ͱ� ��ȯ�� �� �ʿ��� �͵��
			//-Ŭ���� ����
			//-��ġ�� ȸ��
			//-���� �� �� �ϳ� : ���� ��Ģ, Ȥ�� ������ �ΰ�����(�з�����)

			//�Ѿ˿��� �ΰ����� ������ֱ�
			FActorSpawnParameters spawnParam;
			spawnParam.Owner = this; // ���� : ������ ��ü, �������� �߻��� �θ� �� �ĺ�
			spawnParam.Instigator = GetInstigator(); // ��������ΰ�? (*������� : �𸮾󿡼� ���� �� ���� ������ �����͸� ���� ���)
			                                         //GetInstigator : ������ �⺻��
			// ���ʿ� ������� ���� ��, �������� ���� ������ �⺻���� ������ �ִ� (�׸��� ������ �״�� �ᵵ �ȴ�)

			ACPP_Bullet* bulletSpawned = world->SpawnActor<ACPP_Bullet>(
				bullet,
				shootLocation,
				shootRotation,
				spawnParam);

			//������ �Ѿ��� �����Ѵٸ� ���� �� �Ʒ��� ȣ���ϸ� �ȴ�
			if (bulletSpawned) // ������ �Ѿ˿� �ٸ� ������ ���ٸ�
			{
				FVector moveDirection = shootRotation.Vector(); // ȸ�������� ����ȭ
				bulletSpawned->Fire(moveDirection); // C++�� ����ȯ �ʿ���� ���� ����ȣ�� ����
			}
		}
	}
}

