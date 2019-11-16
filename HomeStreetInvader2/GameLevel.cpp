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

			invader->transform->SetPosition(60.0F + i * 40.0F, 60.0F + j * 40.0F);
			invader->transform->SetScale(0.5, 0.5);
			invader->Initialize();
			invader->StartInvader();
		}
	}

	CurrentPlayer = (NepPlayer*)PushBackGameObject(new NepPlayer());
	CurrentPlayer->transform->SetPosition(640, 600);
}

int InvaderMovementVec = 30;		// 적들이 움직이는 속력과 방향
float InvaderRelativeVec = 0.0F;	// 적들이 움직인 거리
void GameLevel::UpdateWithDeltaSecond(float DeltaTime)
{
	float MoveSize = DeltaTime * InvaderMovementVec;
	for (auto inv : SpawnedInvaders) {
		inv->transform->SetPosition(inv->transform->position.x + MoveSize, inv->transform->position.y);
	}
	InvaderRelativeVec += MoveSize;

	if (InvaderRelativeVec >= 50 || InvaderRelativeVec <= -50) {
		InvaderMovementVec *= -1;
	}
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


void GameLevel::RemoveBullet(TextBook * Bullet)
{
	for (int i = 0; i < BulletOfTextBooks.size(); ++i) {
		if (BulletOfTextBooks[i] == Bullet) {
			BulletOfTextBooks.erase(BulletOfTextBooks.begin() + i);
			Destroy(Bullet);
			return;
		}
	}
}

void GameLevel::RemoveBullet(Pencil * Bullet)
{
	for (int i = 0; i < BulletOfPencils.size(); ++i) {
		if (BulletOfPencils[i] == Bullet) {
			BulletOfPencils.erase(BulletOfPencils.begin() + i);
			Destroy(Bullet);
			return;
		}
	}
}

void GameLevel::RemoveInvader(Invader * CurrentInvader)
{
	for (int i = 0; i < SpawnedInvaders.size(); ++i) {
		if (SpawnedInvaders[i] == CurrentInvader) {
			SpawnedInvaders.erase(SpawnedInvaders.begin() + i);
			Destroy(CurrentInvader);
			return;
		}
	}
}

GameLevel::~GameLevel()
{
}
