#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Core/Framework.h"
#include "SplashLevel.h"


// Play Background Music!
//BackgroundSound = new SoundEvent();
//BackgroundSound->LoadFile(L"./Resources/Hibikase.mp3");
//BackgroundSound->Play();


int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));


	Framework& f = Framework::GetInstance();
	f.Run(new SplashLevel(), L"Home Street Invader!", 1280, 720, false);
	return 0;
}