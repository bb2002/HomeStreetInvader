#include "Invader.h"
#include <cstdlib>
#include "GameLevel.h"

// =-=-=-=-=-=-=-= INVADER SETTINGS =-=-=-=-=-=-=-=-=
const float INVADER_MOVEMENT_SIZE = 40;
const float INVADER_SPEED = 50;
/////////////////////////////////////////////////////

Invader::Invader(EInvaderType InvaderType) : GameObject(GetPathFromType(InvaderType))
{
	InvaderMoveVector = INVADER_SPEED;
}

void Invader::SetInvaderPower(float Delay)
{
	switch (InvaderType) {
	case EInvaderType::E_INVADER_1:
		InvaderLevel = 120;
		break;
	case EInvaderType::E_INVADER_2:
		InvaderLevel = 80;
		break;
	case EInvaderType::E_INVADER_3:
		InvaderLevel = 40;
		break;
	}

	NextDelay = std::rand() % InvaderLevel;
}

void Invader::Initialize()
{
	
}



void Invader::StartInvader()
{
	bIsInvaderRunning = true;
}

void Invader::UpdateWithDelta(float DeltaTime)
{
	DeltaTime /= 1000;

	if (bIsInvaderRunning) {
		// Movement
		if (InvaderMovedSize < -INVADER_MOVEMENT_SIZE || InvaderMovedSize > INVADER_MOVEMENT_SIZE) {
			InvaderMoveVector *= -1;
		}

		Vector2 vec = transform->position;
		float size = InvaderMoveVector * (DeltaTime / 1000);
		vec.x += size;
		InvaderMovedSize += size;
		transform->SetPosition(vec.x, vec.y);

		// Shoot
		NextDelay -= DeltaTime;
		if (NextDelay < 0) {
			try {
				GameLevel& CurrentLevel = dynamic_cast<GameLevel&>(Scene::GetCurrentScene());
				Pencil* NewPencil = new Pencil(std::rand() % 100 + 100);

				CurrentLevel.SpawnBullet(NewPencil, this);
			}
			catch (std::bad_cast& ex) {
				std::cout << "[HSI Error] " << ex.what() << std::endl;
			}


			NextDelay = std::rand() % InvaderLevel;
		}
	}
}

Invader::~Invader()
{
}
