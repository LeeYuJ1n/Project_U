// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Bullet.h"

// Sets default values
ACPP_Bullet::ACPP_Bullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������ ���ÿ� ���� ���

	collision = CreateDefaultSubobject<USphereComponent>(TEXT("Bullet Mesh"));
	// CreateDefaultSubobject : ������Ʈ ���������� ����Ʈ ������ ���� ������Ʈ �����
	//                          (����Ʈ�� �������� ó�� ȣ��� ����� ����Ʈ�� �ȴ�)
	//                          * ��� ������ ������Ʈ�� ������� �� �̸��� �ʿ��ϴ�

	collision->InitSphereRadius(10.0f); // ��ü�� �������� �����ϴ� �Լ�

	RootComponent = collision; // ���������� ��Ʈ ������Ʈ�� (��ü��) ����

	// ������ ����

	movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Bullet Movement"));

	movement->SetUpdatedComponent(collision); // ������Ʈ ���� ���� ���� (���� ��翡 �������� ���󰡰�)

	movement->InitialSpeed = 3000.0f;
	movement->MaxSpeed = 3000.0;
	movement->bRotationFollowsVelocity = true; //�̵� ���⿡ ��ü�� ȸ�������� ��������
	movement->bShouldBounce = true; // �ε�ġ�� Ƣ��� ���ΰ�?
	movement->Bounciness = 3.0;

	// �¾��� �� �̺�Ʈ ���ε�
	collision->OnComponentHit.AddDynamic(this, &ACPP_Bullet::OnHit);
}

// Called when the game starts or when spawned
void ACPP_Bullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Bullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Bullet::Fire(FVector direction)
{
	movement->Velocity = direction * (movement->InitialSpeed);

}

void ACPP_Bullet::OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& Hit)
{
}

