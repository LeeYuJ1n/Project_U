// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_TMP_9GameModeBase.generated.h"

/**
 * 
 */
UCLASS() // �𸮾��� ���̺귯�� ��ũ��. �� �ڵ尡 �𸮾󿡼� ���̴� �뵵���� Ȯ�ν�Ű�� ��ũ��
		 // ���Ҿ� () �ȿ� �̸� ������ Ű���带 �Է��ϸ� �ΰ� �ɼ��� ������ �� �ִ�
class CPP_TMP_9_API ACPP_TMP_9GameModeBase : public AGameModeBase
		 // Ŭ���� �̸� ���� A : �𸮾��� �ڵ� ����. �� Ŭ������ � ���·� ���еǴ��� �����Ϳ� �˷��ش�
		 // ���п� �빮�ڸ� �տ� ������� �����Ͱ� �ν��� �� �� �ִ�. �ڵ� �����Ϳ��� ������ ���� ��� ����
{
	GENERATED_BODY() // �𸮾�� ��ũ��. ���� ������ ������ �� �ִ� ������� ��Ÿ����

	//�� ������Ʈ���� �ڵ��� �������� Ȯ���ϱ� ���� ���� ���� ��Ģ ���
	//->�������� ������ �����غ��� (=���� ���� �Լ��� �� ������ ȣ��)

	virtual void StartPlay() override; // ���� ���� �Լ�
};
