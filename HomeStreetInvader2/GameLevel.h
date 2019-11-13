#pragma once
#include "Core/Scene.h"
#include <vector>
#include "BackgroundActor.h"
#include "NepPlayer.h"
#include "Invader.h"
#include "TextBook.h"
#include "Pencil.h"

class GameLevel :
	public Scene
{
public:
	GameLevel();

	void Initialize() override;

	~GameLevel();

private:
	// Background
	BackgroundActor* BackgroundView = nullptr;

	// Player
	NepPlayer* CurrentPlayer = nullptr;

	// Enemies
	std::vector<Invader*> SpawnedInvaders;

	// Bullet of TextBook
	std::vector<TextBook*> BulletOfTextBooks;

	// Bullet of Pencil
	std::vector<Pencil*> BulletOfPencils;
};

