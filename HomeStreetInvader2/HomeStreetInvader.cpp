#include <iostream>
#include "Core/Framework.h"
#include "SplashLevel.h"

int main() {
	Framework& f = Framework::GetInstance();
	f.Run(new SplashLevel(), L"Home Street Invader!", 1280, 720, false);
	return 0;
}