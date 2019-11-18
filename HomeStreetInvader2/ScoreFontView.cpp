#include "ScoreFontView.h"
#include <iostream>

ScoreFontView::ScoreFontView(int Score) : GameObject(fontRenderer = new FontRenderer())
{
	font = new Font(L"Arial", 60.0F, 255.0F, 255.0F, 255.0F, 255.0F, true);
	fontRenderer->font = this->font;
	fontRenderer->text = new wchar_t[100];
	_itow_s(Score, fontRenderer->text, 100, 10);
}


ScoreFontView::~ScoreFontView()
{
}
