#pragma once
#include "./Core/GameObject.h"

class NepPlayer : public GameObject
{
public:
	NepPlayer();

	void UpdateWithDelta(float DeltaSecond) override;

	~NepPlayer();
};

