#pragma once
#include "Core/GameObject.h"

enum class EInvaderType : int {
	E_INVADER_1 = 0,
	E_INVADER_2 = 1,
	E_INVADER_3 = 2
};

class Invader : public GameObject
{
public:
	Invader(EInvaderType InvaderType);

	void SetInvaderPower(float Delay);

	virtual void Initialize();

	inline const wchar_t* GetPathFromType(EInvaderType Type) {
		switch (Type) {
		case EInvaderType::E_INVADER_1:
			return L"./Resources/Invader1.png";
		case EInvaderType::E_INVADER_2:
			return L"./Resources/Invader2.png";
		case EInvaderType::E_INVADER_3: default:
			return L"./Resources/Invader3.png";
		}
	}

	void StartInvader();

	void UpdateWithDelta(float DeltaTime) override;

	~Invader();

private:
	bool bIsInvaderRunning = false;

	float InvaderMoveVector = 0;

	float InvaderMovedSize = 0;

	float InvaderAttackDelay = 0;
	float NextDelay = 0;
	int InvaderLevel = 0;

	EInvaderType InvaderType = EInvaderType::E_INVADER_1;
};

