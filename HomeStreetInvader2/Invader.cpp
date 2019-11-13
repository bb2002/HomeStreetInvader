#include "Invader.h"

Invader::Invader(EInvaderType InvaderType) : GameObject(GetPathFromType(InvaderType))
{
	
}

void Invader::SetInvaderPower(float Delay, float ShootNum)
{
}

void Invader::Initialize()
{
	
}



void Invader::StartInvader()
{

}

void Invader::Update()
{
	if (InvaderMovedSize < -120 || InvaderMovedSize > 120) {
		InvaderMoveVector *= -1;
	}

	Vector2 vec = transform->position;
	vec.x += InvaderMoveVector;
	InvaderMovedSize += InvaderMoveVector;
	transform->SetPosition(vec.x, vec.y);
}

Invader::~Invader()
{
}
