#include "YouDieBackgroundActor.h"



YouDieBackgroundActor::YouDieBackgroundActor(bool die) : GameObject(die ? L"Resources/YouDie.png" : L"Resources/Win.png")
{
}


YouDieBackgroundActor::~YouDieBackgroundActor()
{
}
