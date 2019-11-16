#include "Pencil.h"
#include "GameLevel.h"

Pencil::Pencil(float BulletSpeed) : GameObject(L"./Resources/BulletOfPencil.png")
{
	this->BulletSpeed = BulletSpeed;
}

void Pencil::UpdateWithDelta(float DeltaTime)
{
	// Bullet Movement
	float y = transform->position.y;
	y += BulletSpeed * DeltaTime;
	transform->SetPosition(transform->position.x, y);

	GameLevel& CurrentLevel = dynamic_cast<GameLevel&>(Scene::GetCurrentScene());

	// Check Out of world.
	if (y > 720) CurrentLevel.RemoveBullet(this);

	// Check Character Collision
	if (Collision.Intersected(CurrentLevel.GetCurrentPlayer()->GetCollision())) {
		std::cout << "PLAYER DEAD!" << std::endl;
		CurrentLevel.RemoveBullet(this);
	}
}


Pencil::~Pencil()
{
}
