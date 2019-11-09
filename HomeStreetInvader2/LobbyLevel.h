#pragma once
#include "./Core/Scene.h"
#include <vector>
#include "BackgroundActor.h"
#include "Invader.h"
#include "PressAnyKeyToStart.h"
#include "./Core/SoundEvent.h"

class LobbyLevel :
	public Scene
{
public:
	LobbyLevel();

	virtual void Initialize();

	void Update() override;

	~LobbyLevel();

private:
	BackgroundActor* BackgroundView = nullptr;

	PressAnyKeyToStart* paktsView = nullptr;

	SoundEvent* BackgroundSound = nullptr;

	std::vector<Invader*> SpawnedInvaders;
};

