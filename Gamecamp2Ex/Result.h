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
	void SceneBack(Repush *repush);
	int LoadSounds();
private:
	Button backButton;
	int mpX;
	int mpY;
	int GameClearBGM;
	int click;
};