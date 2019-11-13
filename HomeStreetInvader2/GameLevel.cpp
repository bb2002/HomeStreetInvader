#include "GameLevel.h"



GameLevel::GameLevel()
{
}

void GameLevel::Initialize()
{
	// Draw Background View
	BackgroundView = (BackgroundActor*)PushBackGameObject(new BackgroundActor());
	BackgroundView->transform->SetPosition(640, 360);

	auto SelectInvaderType = [](int a) -> EInvaderType {
		if (a >= 0 && a <= 2) {
			return EInvaderType::E_INVADER_3;
		}
		if (a >= 3 && a <= 5) {
			return EInvaderType::E_INVADER_2;
		}
		if (a >= 6 && a <= 8) {
			return EInvaderType::E_INVADER_1;
		}
		return EInvaderType::E_INVADER_1;
	};

	// 적을 미리 스폰하도록 한다.
	for (int i = 0; i < 30; ++i) {
		for (int j = 0; j < 9; ++j) {
			Invader* invader = (Invader*)PushBackGameObject(new Invader(SelectInvaderType(j)));
			SpawnedInvaders.push_back(invader);

			invader->transform->SetPosition(60 + i * 40, 60 + j * 40);
			invader->transform->SetScale(0.5, 0.5);
		}
	}

	CurrentPlayer = (NepPlayer*)PushBackGameObject(new NepPlayer());
	CurrentPlayer->transform->SetPosition(640, 600);
}


GameLevel::~GameLevel()
{
}
