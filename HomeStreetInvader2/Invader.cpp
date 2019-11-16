#include "Invader.h"
#include <cstdlib>
#include "GameLevel.h"

// =-=-=-=-=-=-=-= INVADER SETTINGS =-=-=-=-=-=-=-=-=
const float INVADER_MOVEMENT_SIZE = 40;
/////////////////////////////////////////////////////

Invader::Invader(EInvaderType InvaderType) : GameObject(GetPathFromType(InvaderType))
{

}


void Invader::Initialize()
{
	switch (InvaderType) {
	case EInvaderType::E_INVADER_1:
		InvaderLevel = 100;
		break;
	case EInvaderType::E_INVADER_2:
		InvaderLevel = 60;
		break;
	case EInvaderType::E_INVADER_3:
		InvaderLevel = 10;
		break;
	}

	NextDelay = (float)(std::rand() % InvaderLevel);
	
}



void Invader::StartInvader()
{
	bIsInvaderRunning = true;
}

void Invader::UpdateWithDelta(float DeltaTime)
{
	if (bIsInvaderRunning) {
		NextDelay -= DeltaTime;

		if (NextDelay < 0) {
			GameLevel& CurrentLevel = dynamic_cast<GameLevel&>(Scene::GetCurrentScene());
			Pencil* NewPencil = new Pencil(std::rand() % 100 + 500.0F);
			CurrentLevel.SpawnBullet(NewPencil, this);
			NextDelay = (float) (std::rand() % InvaderLevel);
		}
	}
}

Invader::~Invader()
{
}
