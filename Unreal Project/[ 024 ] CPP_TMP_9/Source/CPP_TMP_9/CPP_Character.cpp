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
	
	// ���� �����ؼ� ĳ���Ϳ��� �ٿ��ֱ� : �ʿ��� �� ���� ����
	// GetWorld()->SpawnActor() <- �⺻��. ���� ���迡�� ���� ���� ��� ȣ��

	// ���� ���Ϳ��� �߰��� �Ű��������� �ʿ��ϴ�
	// 1. ������ ���� �ǰ� 2. ��� ������� �ǰ�
	// 3. ���� �� � ��Ģ�� ������ ���ΰ� (���� �� ��Ģ, Ȥ�� ���� ����� �߰� ����)

	// ���� ���Ϳ� �ռ� ��� ������ �������� �̸� ����
	FActorSpawnParameters gunParam;
	gunParam.Owner = this; // Owner : ������ �����ϴ� ��ü.
	                       // Ȥ�� �θ��ڽ� ���踦 �����Ѵٸ� 1������ ���ֵ� �ĺ�
	gunParam.Instigator = GetInstigator(); // intigator : ���ӿ��� ������ ����ϴ� ������� �Ǻ��ϴ� �����ڷ�
	                                       // ���⼭�� �⺻ �������� ����Ѵ�
	// ���� �� �ڵ��� ���� "���� �����ϴ� ������ ���� �� �����̰�, ���ӿ� ���Ǵ� �������̴�"

	//���� ���� Ŭ�������� ���� ���� ��, ����� �ִ� ������ �Ҵ�
	gun = GetWorld()->SpawnActor<ACPP_Gun>(
		gunOrigin,
		gunLocation,
		//GetActorRotation // ������ ȸ�� ���� �Ȱ��� �ֱ�
		FRotator(0, 0, 0),
		gunParam);

	// ���� ĳ���Ϳ��� ���̱�
	gun->EquipTo(this);

	//--------------------------------------

	if (Cast<APlayerController>(GetController()))
		//1. Cast<APlayerController>(GetController()) : GetController�� ��ȯ �����͸� PlayerController �ڷ������� ����ȯ
		// -> (APlayerController)GetController() �� �ڵ�� ���� �Ȱ���. = �ٿ�ĳ����(���� ��Ʈ�ѷ��� �÷��̾������)
		// -> �ٸ� Cast�� �� �� ���̸� ����ȯ�� ������ �̷������ �ʰ�, "������ ���"��� ������ �Ǵ��� ��츸 ����ȯ�� �����ش�
		//2. �̰� ���ǹ��̶�� �̾߱�� �ᱹ "��Ʈ�ѷ��� �ִ°�?" + "�÷��̾�� �� ��Ʈ�� ������ �ִ°�?"�� ���� ��
		//  -> GetController�� ����� ���ų�, Cast�� ���� ����ȯ�� �̷������ ������ �� ���ǹ��� false�� �ȴ�
		//1+2. �� ���ǹ��� ���� : ���۱��� ������ �׳� ������ �� �ϰڴ� �� (�������Ʈ���� IsValid ���� �Ͱ� �Ȱ���)
	{
		//�׷��� �� ���� ���� ������ ���Դ� �̾߱� = �÷��̾�� ���� ������ �ٿ��� ���� �ִٴ� �̾߱�

		// �÷��̾� ��Ʈ�ѷ��� �ٿ�ĳ������ ������ ��Ʈ�ѷ�
		APlayerController* playerController =
			Cast<APlayerController>(GetController());

		//�ش� ��Ʈ�ѷ���, ���� �Է°� �߰��, ����ý��ۿ� ����
		UEnhancedInputLocalPlayerSubsystem* subsystem =
			ULocalPlayer::GetSubsystem
			<UEnhancedInputLocalPlayerSubsystem>
			(playerController->GetLocalPlayer());
		//-> �������Ʈ�� ����ý��� ã��� �Ȱ��� ����, �Ȱ��� ���

		//ã�Ƴ� ����ý��ۿ� Ű ������ �߰����ָ� �ȴ� (�������Ʈ�� �Ȱ���)
		subsystem->AddMappingContext(MappingContext, 0);
	}
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

	//PlayerInputComponent->BindAxis
	//("Legacy_MoveForward", this, &ACPP_Character::MoveForward);
	//PlayerInputComponent->BindAxis
	//("Legacy_MoveRight", this, &ACPP_Character::MoveRight);
	//
	//PlayerInputComponent->BindAxis
	//("Legacy_LookUp", this, &ACPP_Character::LookUp);
	//PlayerInputComponent->BindAxis
	//("Legacy_LookRight", this, &ACPP_Character::LookRight);

	// BindAction : ������ ���� �Է¿� �Լ��� �Ҵ��ϴ� �Լ�
	// �Ű����� �� ��° IE_Pressed : Ű�� ������ �� �����Ѵٴ� ��
	//                 IE_Released : Ű�� ������ �����Ѵ�

	//PlayerInputComponent->BindAction
	//("Legacy_Jump", IE_Pressed, this, &ACPP_Character::JumpAction);
	//PlayerInputComponent->BindAction
	//("Legacy_Shoot", IE_Pressed, this, &ACPP_Character::ShootAction);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (Input != nullptr) // �����Ϳ� ���� IsValid ���� ����
	{
		//���� �Է¿� �Լ��� ���ε�
		Input->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ACPP_Character::EI_Move);
		// �Ű����� : ������ �Է� �׼�, �Է��� ���� ���� ��Ȳ, �Լ� ���� ��ü�� �Լ��� ������

		Input->BindAction(Input_Look, ETriggerEvent::Triggered, this, &ACPP_Character::EI_Look);
		Input->BindAction(Input_Shoot, ETriggerEvent::Started, this, &ACPP_Character::EI_Shoot);

		Input->BindAction(Input_Jump, ETriggerEvent::Started, this, &ACharacter::Jump);
		Input->BindAction(Input_Jump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	}
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
	gun->Fire(bullet);
}

void ACPP_Character::EI_Move(const FInputActionValue& value)
{
	//Get ���ø� �Լ��� ����ؼ� ���ϴ� �ڷ��� �����ϱ�
	FVector2D movementVector = value.Get<FVector2D>();

	if (Controller != nullptr) // IsValid
	{
		//ȸ�� ����
		FRotator rotation = Controller->GetControlRotation(); // �������Ʈ�� �þ�(����) ȸ�� �ޱ�

		//������ ���� ȸ�� ������ �����ؼ� ��(yaw, �¿�ȸ��) ���� �ޱ� (�������Ʈ������ ��Ŭ�� ���ط� ����)
		FRotator yawRotation(0, rotation.Yaw, 0); //x, z ȸ������ 0�� �� ���� �־ ȸ������ ����

		//FVector forwardDirection = FRotationMatrix(yawRotation).GetScaledAxis(EAxis::X); //�Է� ���谪�� ���� ������ ���� ��ġ
		FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X); // 0,1�� �ִ� �����ప (��������)
		FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(forwardDirection, movementVector.Y);
		// �� ������ X�� �Է��� Y��? : ������ X�� �� Ʈ������ ����� �׷���. �Է��� Y�� �� �츮�� �׷��� ������ �Ŷ�.

		AddMovementInput(rightDirection, movementVector.X);
	}
}

void ACPP_Character::EI_Look(const FInputActionValue& value)
{
	//�þ� ���� ����
	FVector2D lookVector = value.Get<FVector2D>();

	if (Controller != nullptr) // IsValid
	{
		AddControllerPitchInput(lookVector.Y);
		AddControllerYawInput(lookVector.X);
	}
}

void ACPP_Character::EI_Shoot(const FInputActionValue& value)
{
	//�Ű������� �����ϰ� �״�� �ѿ��� �Ѿ� �߻�
	gun->Fire(bullet);
}

