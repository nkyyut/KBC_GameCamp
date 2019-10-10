#include "Source.h"
#include "DxLib.h"
#include "Result.h"

/// /// <summary>
/// リザルト画面を描画します
/// </summary>
void ResultScene::DrawResult()
{
	SetFontSize(_FONTSIZE_S);

	GetMousePoint(&this->mpX, &this->mpY);

	LoadGraphScreen(0, 0, "Assets/ResultImage.png", false);
	DrawFormatString(0, 0, 0xffffff,"%d, %d", mpX, mpY);
	this->backButton.DrawButton();

	this->SceneBack();

	if (opt.Kflg & PAD_INPUT_M)
	{
		GAMESTATE = GAME_INIT;
	}
}

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

/// <summary>
/// リザルトを初期化
/// </summary>
void ResultScene::Init()
{
	this->backButton.image = LoadGraph("Assets/backButton.png");
	this->backButton.SetButtonPosition(512,635);
	this->backButton.SetHitPos(420,600,610,660);
}

/// <summary>
/// タイトル画面へ遷移する処理
/// スタートボタンとマウスの当たり判定を行う
/// マウスが押されると判定を行う
/// </summary>
void ResultScene::SceneBack()
{
	int mouse = GetMouseInput();

	if (mouse && MOUSE_INPUT_LEFT) {
		if (backButton.ChackHit(mpX, mpY) == 1) {
			GAMESTATE = GAME_TITLE;
		}
	}
}