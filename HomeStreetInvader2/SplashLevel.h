#pragma once
#include "Core/Scene.h"
#include "HomeStreetInvaderLogo.h"

class SplashLevel :
	public Scene
{
public:
	SplashLevel();

public:
	virtual void Initialize();

	void Update() override;

	~SplashLevel();

private:
	HomeStreetInvaderLogo* Logo;
};

