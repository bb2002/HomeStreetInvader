#pragma once
#include "Core/GameObject.h"
#include "Core/AABBCollider.h"
class Pencil : public GameObject
{
public:
	Pencil(float BulletSpeed);

	void UpdateWithDelta(float DeltaTime) override;

	float BulletSpeed = 0.0F;

	~Pencil();

private:
	AABBCollider Collision = AABBCollider(*transform, Vector2(20.0F, 20.0F));
};

