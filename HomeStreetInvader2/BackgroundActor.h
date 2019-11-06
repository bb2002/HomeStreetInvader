#pragma once
#include "./Core/GameObject.h"

class BackgroundActor : public GameObject
{
public:
	BackgroundActor();

	virtual void Initialize();

	~BackgroundActor();
};

