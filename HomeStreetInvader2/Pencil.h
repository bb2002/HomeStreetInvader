#pragma once
#include "Core/GameObject.h"
class Pencil : public GameObject
{
public:
	Pencil(float BulletSpeed);

	void UpdateWithDelta(float DeltaTime) override;

	float BulletSpeed = 0.0F;

	~Pencil();
};

