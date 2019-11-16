#pragma once
#include "./Core/GameObject.h"
#include "./Core/AABBCollider.h"

class TextBook : public GameObject
{
public:
	TextBook();

	void UpdateWithDelta(float DeltaTime) override;

	inline AABBCollider& GetCollision() {
		return Collision;
	}

	~TextBook();

private:
	AABBCollider Collision = AABBCollider(*transform, Vector2(20, 20));
};

