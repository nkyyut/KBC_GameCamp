#include "Source.h"
#include "DrawTitle.h"
#include "DxLib.h"

/// <summary>
/// タイトル画面を描画します
/// </summary>
void TitleScene::DrawTitle() 
{
	SetFontSize( _FONTSIZE_S );

	GetMousePoint(&this->mpX, &this->mpY);

	LoadGraphScreen(0,0, "Assets/TitleImage.png", false);
	this->startButton.DrawButton();
	this->endButton.DrawButton();

	this->StartGame();
	this->EndGame();

	if( opt.Kflg & PAD_INPUT_M )
	{
		GAMESTATE = GAME_INIT;
	}
}

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

/// <summary>
/// タイトルを初期化
/// </summary>
void TitleScene::Init() 
{
	this->startButton.image = LoadGraph("Assets/startButtom.png");
	this->endButton.image = LoadGraph("Assets/endButton.png");
	startButton.SetButtonPosition(530, 600);
	endButton.SetButtonPosition(540, 670);
	startButton.SetHitPos(395, 574, 610, 632);
	endButton.SetHitPos(433, 636, 642, 693);
}

/// <summary>
/// ゲームのスタート処理
/// スタートボタンとマウスの当たり判定を行う
/// マウスが押されると判定を行う
/// </summary>
void TitleScene::StartGame()
{
	int mouse = GetMouseInput();

	if (mouse && MOUSE_INPUT_LEFT){
		if (startButton.ChackHit(mpX, mpY) == 1) {
			GAMESTATE = GAME_INIT;
		}
	}
}

/// <summary>
/// ゲームのエンド処理
/// エンドボタンとマウスの当たり判定を行う
/// マウスが押されると判定を行う
/// </summary>
void TitleScene::EndGame()
{
	int mouse = GetMouseInput();

	if (mouse && MOUSE_INPUT_LEFT) {
		if (endButton.ChackHit(mpX, mpY) == 1) {
			GAMESTATE = GAME_END;
		}
	}
}