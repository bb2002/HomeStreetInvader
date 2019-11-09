#include <iostream>
#include "PressAnyKeyToStart.h"
#include "Core/InputManager.h"
#include "Core/Scene.h"
#include "GameLevel.h"

PressAnyKeyToStart::PressAnyKeyToStart() : GameObject(L"./Resources/PressAnyKeyToStart.png")
{
}

void PressAnyKeyToStart::Update()
{
	if (InputManager::IsAnyKeyPressed()) {
		Scene::ChangeScene(new GameLevel());
	}
}


PressAnyKeyToStart::~PressAnyKeyToStart()
{
}
