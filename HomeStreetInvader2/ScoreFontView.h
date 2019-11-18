#pragma once
#include "Core/GameObject.h"
#include "Core/FontObject.h"
#include "Core/FontRenderer.h"
#include "Core/Font.h"

class ScoreFontView :
	public GameObject
{
public:
	ScoreFontView(int Score);
	~ScoreFontView();

private:
	Font* font;						//자세한 설명은 Font.h 참고
	FontRenderer* fontRenderer;		//자세한 설명은 FontRenderer.h 참고
	wchar_t str[100];
};

