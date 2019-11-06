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

auto CurrentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
void SplashLevel::Update()
{
	auto Now = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	if ((Now - CurrentTime).count() > 3000) {
		Scene::ChangeScene(new LobbyLevel());
	}
}

SplashLevel::~SplashLevel()
{
	Destroy(Logo);
}
