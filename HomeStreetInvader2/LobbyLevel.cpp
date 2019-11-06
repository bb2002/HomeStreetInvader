#include "LobbyLevel.h"



LobbyLevel::LobbyLevel()
{
}

void LobbyLevel::Initialize()
{
	BackgroundView = (BackgroundActor*)PushBackGameObject(new BackgroundActor());
	BackgroundView->transform->SetPosition(640, 360);
}


LobbyLevel::~LobbyLevel()
{
}
