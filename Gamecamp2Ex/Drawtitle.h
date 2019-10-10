#pragma once

#include "Button.h"

class  TitleScene
{
public:
	 TitleScene();
	~ TitleScene();
	void DrawTitle();	
	void Init();
	void StartGame();
	void EndGame();
	void GameEnd();
	int LoadSounds();
	
	
private:
	Button startButton;
	Button endButton;
	int mpX;
	int mpY;
	int TitleBGM;
	int ClickSE;
	
};