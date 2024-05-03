// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_TMPGameModeBase.h"

void ACPP_TMPGameModeBase::StartPlay()
{
    //BeginPlay ����

    //�θ� Ŭ�����μ� ����(�� ��Ģ�� ����) �����ϱ�
    Super::StartPlay();

    //�����Ϳ� ���� ���������� �ƴ϶� �ڵ��� ���� �ǵ��� �������� Ȯ���ϱ� ���� �α�
    
    if (GEngine) // <-������ Ȥ�� ���尡 ���� ���̸�
    {
        UE_LOG(LogTemp, Log, TEXT("Hello, world!"));
        // UE_LOG : �⺻���� �𸮾� �α� �Լ� ��ũ��
        // �Ű����� : LogTemp - ���� ���� �ӽ� �α׶� ��.
        //           �� �ܿ� ���� �޽���, �� �뵵�� ���� �޽��� ������ �ִ�
        //           Log - �޽����� ���� �з�
        //           TEXT - ���� �޽���

        GEngine->AddOnScreenDebugMessage
            (-1, 5.0f, FColor::Purple, TEXT("This is a Game!"));
        // GEngine->AddOnScreenDebugMessage : ������ �����ڿ� ������� ����� �޽��� ����
        // ...��ǻ� �α׿� ����ϴٰ� ���� �ȴ� (�뵵 ���к��ٴ� ���� �������� ���ü��� ����)
        // �Ű����� : ù ��° ���� - �޽����� Ű (����)
        //           �� ��° ���� - �޽��� ��� �ð�
        //           ���� enum - �޽��� ����
        //           TEXT() - ���� �޽���
    }
}