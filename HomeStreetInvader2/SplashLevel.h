#pragma once
#include "Core/Scene.h"
#include "HomeStreetInvaderLogo.h"
#include "SoundPool.h"


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

	bool isLoadEnd = false;
};

void LoadAudioAssets(SoundEvent**, SoundEvent**, SoundEvent**, SoundEvent**, SoundEvent**, SoundEvent**, SoundEvent**, bool*) noexcept;
