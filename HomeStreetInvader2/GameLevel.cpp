#include "GameLevel.h"



GameLevel::GameLevel()
{
}

void GameLevel::Initialize()
{
	// Draw Background View
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
			invader->SetInvaderPower(3000000);
			invader->StartInvader();
		}
	}

	CurrentPlayer = (NepPlayer*)PushBackGameObject(new NepPlayer());
	CurrentPlayer->transform->SetPosition(640, 600);
}

void GameLevel::SpawnBullet(TextBook * Bullet)
{
	Vector2 Pos = CurrentPlayer->transform->position;
	Bullet->transform->SetPosition(Pos.x, Pos.y - 50);
	PushBackGameObject(Bullet);
	BulletOfTextBooks.push_back(Bullet);
}

void GameLevel::SpawnBullet(Pencil * Bullet, Invader* self)
{
	Vector2 Pos = self->transform->position;
	Bullet->transform->SetPosition(Pos.x, Pos.y);
	PushBackGameObject(Bullet);
	BulletOfPencils.push_back(Bullet);
}


GameLevel::~GameLevel()
{
}
