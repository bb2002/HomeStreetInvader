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
	Font* font;						//�ڼ��� ������ Font.h ����
	FontRenderer* fontRenderer;		//�ڼ��� ������ FontRenderer.h ����
	wchar_t str[100];
};

