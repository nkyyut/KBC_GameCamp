#pragma once

#include "Button.h"

class  ResultScene
{
public:
	ResultScene();
	~ResultScene();
	void DrawResult();
	void Init();
	void SceneBack();
private:
	Button backButton;
	int mpX;
	int mpY;
};