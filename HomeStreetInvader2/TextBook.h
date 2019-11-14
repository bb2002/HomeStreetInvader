#pragma once
#include "./Core/GameObject.h"

class TextBook : public GameObject
{
public:
	TextBook();

	void UpdateWithDelta(float DeltaTime) override;

	~TextBook();
};

