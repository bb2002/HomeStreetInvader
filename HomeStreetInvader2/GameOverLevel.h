#pragma once
#include "Core/Scene.h"
#include "YouDieBackgroundActor.h"
#include "ScoreFontView.h"
#include "LobbyLevel.h"

class GameOverLevel :
	public Scene
{
public:
	GameOverLevel(bool isWin, int score, float playTime);

	void Initialize() override;

	void UpdateWithDeltaSecond(float DeltaTime) override;

	~GameOverLevel();

private:
	bool isWin = false;

	int score = 0;

	float PlayTime = 0.0F;

	YouDieBackgroundActor* Background = nullptr;
	ScoreFontView* ScoreView = nullptr;
};

