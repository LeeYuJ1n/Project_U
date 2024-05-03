// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_TMPGameModeBase.generated.h"

/**
 * 
 */
UCLASS() //<-UCLASS : �𸮾� ������ ��ũ��, "�̰��� �𸮾�� Ŭ�����Դϴ�."
		 // () : �𸮾�� ��ũ���� Ư¡, �Ű������� �߰� �����ؼ� �ɼ� Ȯ�� ����
class CPP_TMP_API ACPP_TMPGameModeBase : public AGameModeBase
		//Ŭ���� �̸� �տ� ���� A : �𸮾󿡼� ������ ����� �޾� ������ٴ� �ǹ�
{
	GENERATED_BODY() // �𸮾󿡼� ��ü�� ������ �� ������ ��Ÿ���� ��ũ��

	// BeginPlay�� �����ϴ� �ڵ���� ���� �Լ� (�� ��° �����ڿ� ����)
	virtual void StartPlay() override;
};
