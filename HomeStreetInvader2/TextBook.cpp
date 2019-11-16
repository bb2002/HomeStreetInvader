#include "TextBook.h"
#include "GameLevel.h"


// =-=-=-=-=-=-= Bullet settings ....
const float BULLET_SPEED = 800;
/////////////////////////////////////


TextBook::TextBook() : GameObject(L"./Resources/BulletOfTextBook.png")
{

}

void TextBook::UpdateWithDelta(float DeltaTime)
{
	float y = transform->position.y;
	y -= BULLET_SPEED * DeltaTime;
	transform->SetPosition(transform->position.x, y);

	GameLevel& CurrentLevel = dynamic_cast<GameLevel&>(Scene::GetCurrentScene());

	if (y < -50) {
		CurrentLevel.RemoveBullet(this);
	}
	
	// Invader �� �浹�ϴ��� Ȯ�� �Ѵ�.
	auto Invaders = CurrentLevel.GetInvaders();
	for (auto i : Invaders) {
		if (Collision.Intersected(i->GetCollision())) {
			CurrentLevel.RemoveBullet(this);
			CurrentLevel.RemoveInvader(i);
		}
	}
}


TextBook::~TextBook()
{

}
