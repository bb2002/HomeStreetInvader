#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Core/Framework.h"
#include "SplashLevel.h"
#include "Core/SoundEvent.h"

// Play Background Music!
//BackgroundSound = new SoundEvent();
//BackgroundSound->LoadFile(L"./Resources/Hibikase.mp3");
//BackgroundSound->Play();

extern SoundEvent* BackgroundMusic = nullptr;		// 배경 음악
extern SoundEvent* InvaderDead = nullptr;			// 적 사망 소리
extern SoundEvent* InvaderShoot = nullptr;			// 적 발사 소리
extern SoundEvent* NeptuneShoot = nullptr;			// 플레이어 발사
extern SoundEvent* PlayerDeadSound = nullptr;		// 플레이어 사망
extern SoundEvent* DefectSound = nullptr;			// 패배 사운드
extern SoundEvent* WinSound = nullptr;				// 승리 사운드


int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	std::cout << "Game loading... please wait." << std::endl;

	// load sounds.
	//BackgroundMusic = new SoundEvent();
	//BackgroundMusic->LoadFile(L"Resources/Hibikase.mp3");

	InvaderDead = new SoundEvent();
	InvaderDead->LoadFile(L"Resources/InvaderDeadSound.wav");

	InvaderShoot = new SoundEvent();
	InvaderShoot->LoadFile(L"Resources/InvaderShoot.wav");

	NeptuneShoot = new SoundEvent();
	NeptuneShoot->LoadFile(L"Resources/NeptuneShoot.mp3");

	PlayerDeadSound = new SoundEvent();
	PlayerDeadSound->LoadFile(L"Resources/PlayerDeadSound.wav");

	DefectSound = new SoundEvent();
	DefectSound->LoadFile(L"./Resources/DefectSound.wav");

	WinSound = new SoundEvent();
	WinSound->LoadFile(L"./Resources/WinSound.mp3");


	Framework& f = Framework::GetInstance();
	f.Run(new SplashLevel(), L"Home Street Invader!", 1280, 720, false);
	return 0;
}