#pragma once
#include "./Core/Scene.h"
#include "BackgroundActor.h"

class LobbyLevel :
	public Scene
{
public:
	LobbyLevel();

	virtual void Initialize();

	~LobbyLevel();

private:
	BackgroundActor* BackgroundView = nullptr;
};

