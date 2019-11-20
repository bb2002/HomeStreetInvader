#include "GameOverLevel.h"
#include "Core/InputManager.h"

GameOverLevel::GameOverLevel(bool isWin, int score, float playTime) : isWin(isWin), score(score), PlayTime(playTime)
{
}

void GameOverLevel::Initialize()
{

	this->Background = (YouDieBackgroundActor*) PushBackGameObject(new YouDieBackgroundActor(!isWin));
	this->Background->transform->SetPosition(640, 360);

	// calc score.
	if (isWin) {
		// win 이면 가산점
		score = score * 100 / PlayTime;
	}

	this->ScoreView = (ScoreFontView*)PushBackGameObject(new ScoreFontView(score));
	this->ScoreView->transform->SetPosition(620, 50);

	BackgroundMusic->Stop();

	if (isWin) {
		if (WinSound != nullptr) {
			WinSound->Play();
		}
	}
	else {
		if (DefectSound != nullptr) {
			DefectSound->Play();
		}
	}
}

float Time = 0.0F;
void GameOverLevel::UpdateWithDeltaSecond(float DeltaTime)
{

	Time += DeltaTime;

	if (Time > 1.0F) {
		if (InputManager::IsAnyKeyPressed()) {
			Scene::ChangeScene(new LobbyLevel());
		}
	}
}


GameOverLevel::~GameOverLevel()
{
}
