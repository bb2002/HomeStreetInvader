#pragma once
#include "./Core/GameObject.h"
class PressAnyKeyToStart : public GameObject
{
public:
	PressAnyKeyToStart();

	void Update() override;

	~PressAnyKeyToStart();
};

