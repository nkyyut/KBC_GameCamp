#pragma once

#include "Button.h"
#include "Repush.h"

class  TitleScene
{
public:
	 TitleScene();
	~ TitleScene();
	void DrawTitle( Repush *repush );	
	void Init();
	void StartGame();
	void EndGame();
private:
	Button startButton;
	Button endButton;
	int mpX;
	int mpY;
};