#include "LobbyLevel.h"
#include <ctime>

LobbyLevel::LobbyLevel()
{
}

void LobbyLevel::Initialize()
{
	
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

	// Press ANY KEY TO START
	paktsView = (PressAnyKeyToStart*)PushBackGameObject(new PressAnyKeyToStart());
	paktsView->transform->SetPosition(640, 650);

	// Play Background Music!
	//BackgroundSound = new SoundEvent();
	//BackgroundSound->LoadFile(L"./Resources/Hibikase.mp3");
	//BackgroundSound->Play();
}

long double BeforeFrameSec = time(0);
float CurrentPos = 650;
void LobbyLevel::Update()
{
	Scene::Update();

	long double DeltaSecond = time(0) - BeforeFrameSec;
	BeforeFrameSec = time(0);

	if (DeltaSecond >= 1) {
		paktsView->transform->SetPosition(640, CurrentPos);
		if (CurrentPos == 650) {
			CurrentPos = -100;
		}
		else {
			CurrentPos = 650;
		}
	}
}


LobbyLevel::~LobbyLevel()
{
}
