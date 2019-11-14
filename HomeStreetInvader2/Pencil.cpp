#include "Pencil.h"
#include "GameLevel.h"


Pencil::Pencil(float BulletSpeed) : GameObject(L"./Resources/BulletOfPencil.png")
{
	this->BulletSpeed = BulletSpeed;
}

void Pencil::UpdateWithDelta(float DeltaTime)
{
	float y = transform->position.y;
	y += BulletSpeed * (DeltaTime / 1000);
	transform->SetPosition(transform->position.x, y);

	if (y > 720) {
		try {
			GameLevel& CurrentLevel = dynamic_cast<GameLevel&>(Scene::GetCurrentScene());
			CurrentLevel.Destroy(this);
		}
		catch (std::bad_cast& ex) {
			std::cout << "[HSI Error] " << ex.what() << std::endl;
		}
	}
}


Pencil::~Pencil()
{
}
