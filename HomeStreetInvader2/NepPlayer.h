#pragma once
#include "./Core/GameObject.h"
#include "Core/AABBCollider.h"

class NepPlayer : public GameObject
{

public:
	NepPlayer();

	void UpdateWithDelta(float DeltaSecond) override;

	inline AABBCollider& GetCollision() {
		return Collision;
	}

	~NepPlayer();

private:
	AABBCollider Collision = AABBCollider(*transform, Vector2(60.0F, 120.0F));
};

