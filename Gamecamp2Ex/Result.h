#pragma once

#include "Button.h"
#include "Repush.h"

class  ResultScene
{
public:
	ResultScene();
	~ResultScene();
	void DrawResult( Repush *repush );
	void Init();
	void SceneBack( Repush *repush );
private:
	Button backButton;
	int mpX;
	int mpY;
};