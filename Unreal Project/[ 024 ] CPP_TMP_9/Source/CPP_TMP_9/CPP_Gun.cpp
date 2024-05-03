// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Gun.h"
#include "CPP_Bullet.h" // ���⼭ �Ѿ� Ŭ���� �б� (������� ��Ŭ������� ���� �� ���⼭ �ϸ� �ȴ�)

// Sets default values
ACPP_Gun::ACPP_Gun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Gun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Gun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Gun::Fire(TSubclassOf<ACPP_Bullet> bulletOrigin)
{
	// �Ѿ��� �߻��Ѵ� = �Ѿ� ���͸� �����Ѵ�
	// (������ �� �Ѿ��� �� ȥ�� �˾Ƽ� ���ư��� �ȴ�)

	// ������ �ʿ��� �� : 1. ����. 2. Ʈ������(�� �����ϴ� ��ġ�� ȸ��) 3. ��Ģ
	// ������ �Ű������� ���� ��Ȳ

	// ��ġ�� ȸ�� = ���� �̹� ����������� �� ���� ��ġ�� ȸ���� �״�� �ָ� �ȴ�
	FVector shootLocation = GetActorLocation();
	FRotator shootRotation = GetActorRotation();

	//���� (���) ��Ģ
	FActorSpawnParameters spawnParam; // �ѿ��� ������ ���ʹ� �Ѿ˻��̶�...
	spawnParam.Owner = this;
	spawnParam.Instigator = GetInstigator();

	// ���� �� ������ ��ħ�� �°� (�������Ʈ�� ġ�ڸ� IsValid ���)
	// ���� ���� �� ���� ���͸� ���

	UWorld* world = GetWorld();

	if (world) // ������ ���� �ε� ���̶��
	{
		//�Ѿ� �����
		ACPP_Bullet* bulletSpawned = world->SpawnActor<ACPP_Bullet>(
			bulletOrigin,
			shootLocation,
			shootRotation,
			spawnParam);

		//�Ѿ��� ���������� ��������ٸ� (�Ѿ˿� IsValid ���� ��Ȳ)
		if (bulletSpawned)
		{
			FVector moveDirection = shootRotation.Vector(); //�������� �ȿ� ���� ��ȯ �Լ� ����
			bulletSpawned->Fire(moveDirection);
			// ������ ���� �ڵ��� ���� �Ѿ˿�, �߻� �Լ��� ȣ�� �� ���� �����ϸ� ��
		}
	}
}

void ACPP_Gun::EquipTo(AActor* parent)
{
	AttachToActor(
		parent, // �θ� Ʈ������
		FAttachmentTransformRules::KeepRelativeTransform); // ��� Ʈ������ ����
}

