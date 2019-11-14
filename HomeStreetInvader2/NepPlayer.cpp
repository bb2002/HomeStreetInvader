#include "NepPlayer.h"
#include <iostream>
#include "Core/InputManager.h"
#include "Core/Scene.h"
#include "GameLevel.h"

#define KEY_W	0x57
#define KEY_A	0x41
#define KEY_S	0x53
#define KEY_D	0x44

// GAME SETTINGS....
const float CHARACTER_SPEED = 200;

////////////////////

NepPlayer::NepPlayer() : GameObject(L"./Resources/Player.png")
{
}

void NepPlayer::UpdateWithDelta(float DeltaSecond)
{
	DeltaSecond /= 1000;

	if (InputManager::GetKeyPressed(KEY_A)) {
		float X = DeltaSecond * CHARACTER_SPEED;
		if (transform->position.x - X > 0) {
			transform->SetPosition(transform->position.x - X, transform->position.y);
		}
	}

	if (InputManager::GetKeyPressed(KEY_D)) {
		float X = DeltaSecond * CHARACTER_SPEED;
		if (transform->position.x + X < 1280) {
			transform->SetPosition(transform->position.x + X, transform->position.y);
		}
	}

	if (InputManager::GetKeyDown(VK_SPACE)) {
		try {
			GameLevel& CurrentLevel = dynamic_cast<GameLevel&>(Scene::GetCurrentScene());
			TextBook* NewBook = new TextBook();

			CurrentLevel.SpawnBullet(NewBook);
		}
		catch (std::bad_cast& ex) {
			std::cout << "[HSI Error] " << ex.what() << std::endl;
		}
	}
}


NepPlayer::~NepPlayer()
{
}
