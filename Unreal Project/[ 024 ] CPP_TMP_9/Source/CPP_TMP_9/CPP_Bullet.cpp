// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Bullet.h"

// Sets default values
ACPP_Bullet::ACPP_Bullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������ ���ÿ� �浹 ������ ����

	collision = CreateDefaultSubobject<USphereComponent>(TEXT("Bullet Collision"));
	//CreateDefaultSubobject : ������Ʈ�� �����ؼ� �Ʒ��� ���̱�
	//                         �߰��� ����Ʈ�� "�� ������Ʈ�� ����Ʈ(��Ʈ) ������ ���̵�,
	//                         ��Ʈ�� ������ ���� �̰� ��Ʈ��"��� ���̴�
	//                         ���Ҿ ��� ������Ʈ�� ������� �� �̸��� �ʿ��ϴ� (TEXT)

	collision->InitSphereRadius(10.0f); // ��ü�� ������ �����ϱ�

	//���� ���� �浹 ������ �ƿ� ��Ʈ�� Ȯ���Ϸ���
	RootComponent = collision; // �������� ���� ��Ʈ�� ���� ����

	// ������ ����

	movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Bullet Movement"));

	movement->SetUpdatedComponent(collision); // *�������� : �������Ʈ���� ������*
										      // �߻�ü �̵� ����� �浹�� ������Ʈ�� ����ȭ�ϰ� �ϴ� ���

	//�߻�ü �̵� �ɼ� (�������Ʈ ���� ����)
	movement->InitialSpeed = 3000.0f;
	movement->MaxSpeed = 3000.0f;
	movement->bRotationFollowsVelocity = true; // �̵� ���⿡ ��ü ȸ���� ���󰡰�
	movement->bShouldBounce = true; // ��Ʈ �߻� �� Ƣ����°�?
	movement->Bounciness = 3.0; // ���� Ƣ��

	//�浹�� ���� ��Ʈ �̺�Ʈ �߻���, Ŭ������ �ִ� OnHit �Լ��� ���ε�
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
	//�߻�ü �̵� ������Ʈ�� �Ű������� ���� ������ �ӵ�ȭ�ؼ� �����ָ� �ȴ�
	movement->Velocity = direction * (movement->InitialSpeed);
	//-> �Ű������� ���� ��ȭ(����) x �ӷ� = �ӵ�
}

void ACPP_Bullet::OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& Hit)
{
}

