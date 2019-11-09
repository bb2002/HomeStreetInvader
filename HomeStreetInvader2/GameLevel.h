#pragma once
#include "Core/Scene.h"
class GameLevel :
	public Scene
{
public:
	GameLevel();

	void Initialize() override;

	~GameLevel();
};

