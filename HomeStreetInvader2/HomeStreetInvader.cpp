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

extern SoundEvent* BackgroundMusic = nullptr;		// ��� ����
extern SoundEvent* InvaderDead = nullptr;			// �� ��� �Ҹ�
extern SoundEvent* InvaderShoot = nullptr;			// �� �߻� �Ҹ�
extern SoundEvent* NeptuneShoot = nullptr;			// �÷��̾� �߻�
extern SoundEvent* PlayerDeadSound = nullptr;		// �÷��̾� ���
extern SoundEvent* DefectSound = nullptr;			// �й� ����
extern SoundEvent* WinSound = nullptr;				// �¸� ����


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