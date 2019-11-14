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
	y -= BULLET_SPEED * (DeltaTime / 1000);
	transform->SetPosition(transform->position.x, y);

	if (y < -50) {
		try {
			GameLevel& CurrentLevel = dynamic_cast<GameLevel&>(Scene::GetCurrentScene());
			CurrentLevel.Destroy(this);
		}
		catch (std::bad_cast& ex) {
			std::cout << "[HSI Error] " << ex.what() << std::endl;
		}
	}
}


TextBook::~TextBook()
{
}
