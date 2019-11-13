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

	void UpdateWithDeltaSecond(float DeltaSec) override;

	~SplashLevel();

private:
	HomeStreetInvaderLogo* Logo;
};

