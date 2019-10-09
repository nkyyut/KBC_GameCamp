#include "Source.h"
#include "DrawTitle.h"

void TitleScene::DrawTitle() 
{
	SetFontSize( _FONTSIZE_S );

	DrawGraph(0,0,this->image, false);

	if( opt.Kflg & PAD_INPUT_M )
	{
		GAMESTATE = GAME_INIT;
	}
}

TitleScene::TitleScene()
{
	this->image = LoadGraph("Assets/TitleImage.png");
}

TitleScene::~TitleScene()
{
}