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

	void UpdateWithDeltaSecond(float DeltaTime) override;

	void SpawnBullet(TextBook* Bullet);

	void SpawnBullet(Pencil* Bullet, Invader* self);

	inline std::vector<Invader*>& GetInvaders() {
		return SpawnedInvaders;
	}

	inline NepPlayer* GetCurrentPlayer() {
		return CurrentPlayer;
	}

	void RemoveBullet(TextBook* Bullet);

	void RemoveBullet(Pencil* Bullet);

	void RemoveInvader(Invader* CurrentInvader);

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

