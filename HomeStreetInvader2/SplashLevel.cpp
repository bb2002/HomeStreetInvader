#include "SplashLevel.h"

#include <iostream>
#include <chrono>
#include <thread>
#include "LobbyLevel.h"

using namespace std::chrono;

SplashLevel::SplashLevel()
{
}

void SplashLevel::Initialize()
{
	Logo = (HomeStreetInvaderLogo*)PushBackGameObject(new HomeStreetInvaderLogo());
	Logo->transform->SetPosition(640, 384);

	std::thread thread(LoadAudioAssets, &BackgroundMusic, &InvaderDead, &InvaderShoot, &NeptuneShoot, &PlayerDeadSound, &DefectSound, &WinSound, &isLoadEnd);
	thread.detach();
}

void SplashLevel::UpdateWithDeltaSecond(float DeltaSec)
{
	if (isLoadEnd) {
		Scene::ChangeScene(new LobbyLevel());
	}
}
void LoadAudioAssets(SoundEvent** BackgroundMusic, SoundEvent** InvaderDead, SoundEvent** InvaderShoot, SoundEvent** NeptuneShoot, SoundEvent** PlayerDeadSound, SoundEvent** DefectSound, SoundEvent** WinSound, bool* isLoadEnd) noexcept
{
	std::cout << "Game loading... please wait." << std::endl;

	// load sounds.
	*BackgroundMusic = new SoundEvent();
	(*BackgroundMusic)->LoadFile(L"Resources/Hibikase.mp3");
	std::cout << "Loading... [1/7]" << std::endl;

	*InvaderDead = new SoundEvent();
	(*InvaderDead)->LoadFile(L"Resources/InvaderDeadSound.wav");
	std::cout << "Loading... [2/7]" << std::endl;

	*InvaderShoot = new SoundEvent();
	(*InvaderShoot)->LoadFile(L"Resources/InvaderShoot.wav");
	std::cout << "Loading... [3/7]" << std::endl;

	*NeptuneShoot = new SoundEvent();
	(*NeptuneShoot)->LoadFile(L"Resources/NeptuneShoot.wav");
	std::cout << "Loading... [4/7]" << std::endl;

	*PlayerDeadSound = new SoundEvent();
	(*PlayerDeadSound)->LoadFile(L"Resources/PlayerDeadSound.wav");
	std::cout << "Loading... [5/7]" << std::endl;

	*DefectSound = new SoundEvent();
	(*DefectSound)->LoadFile(L"./Resources/DefectSound.wav");
	std::cout << "Loading... [6/7]" << std::endl;

	*WinSound = new SoundEvent();
	(*WinSound)->LoadFile(L"./Resources/WinSound.mp3");
	std::cout << "Loading... [7/7]" << std::endl;
	std::cout << "Starting..." << std::endl;

		*isLoadEnd = true;
	
}


SplashLevel::~SplashLevel()
{
	Destroy(Logo);
}
