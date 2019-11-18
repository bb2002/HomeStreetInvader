#pragma once
#include "./Core/GameObject.h"
#include "Core/AABBCollider.h"

class NepPlayer : public GameObject
{

public:
	NepPlayer();

	void UpdateWithDelta(float DeltaSecond) override;

	void YouDie();

	inline void IncreaseScore() {
		PlayerScore++;
	}

	inline AABBCollider& GetCollision() {
		return Collision;
	}

	inline int GetPlayerScore() {
		return PlayerScore;
	}

	inline float GetPlayTime() {
		return PlayTime;
	}

	~NepPlayer();

private:
	AABBCollider Collision = AABBCollider(*transform, Vector2(60.0F, 120.0F));

	int PlayerScore = 0;

	float PlayTime = 0.0F;
};

