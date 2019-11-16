#include "SplashLevel.h"

#include <iostream>
#include <chrono>
#include "LobbyLevel.h"

using namespace std::chrono;

SplashLevel::SplashLevel()
{
}

void SplashLevel::Initialize()
{
	Logo = (HomeStreetInvaderLogo*)PushBackGameObject(new HomeStreetInvaderLogo());
	Logo->transform->SetPosition(640, 384);
}

float TimeLength = 0;
void SplashLevel::UpdateWithDeltaSecond(float DeltaSec)
{
	TimeLength += DeltaSec;
	if (TimeLength > 3) {
		Scene::ChangeScene(new LobbyLevel());
	}
}


SplashLevel::~SplashLevel()
{
	Destroy(Logo);
}
