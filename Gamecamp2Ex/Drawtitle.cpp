#include "Source.h"
#include "DrawTitle.h"
#include "MousePoint.h"
#include "DxLib.h"


/// <summary>
/// タイトル画面を描画します
/// </summary>
void TitleScene::DrawTitle( Repush *repush ) 
{
	repush->NowK = GetMouseInput();
	if( ( repush->NowK == 0 ) && ( repush->OldK != 0 ) )
	{
		repush->OldK = 0;
		repush->rePushFlg = 0;

	}
	SetFontSize( _FONTSIZE_S );

	
	//DrawBox(512, 384, 560, 412, 0x000000, false);

	GetMousePoint(&this->mpX, &this->mpY);

	
	LoadGraphScreen(0,0, "Assets/TitleImage.png", false);

	if (startButton.ChackHit(this->mpX, this->mpY) == 1) {
		DrawLine(407, 633, 655, 633, 0x000000);
	}

	if (endButton.ChackHit(this->mpX, this->mpY) == 1) {
		DrawLine(444, 700, 633, 700, 0x000000);
	}

	if (CheckSoundMem(this->TitleBGM) == 0) {
		PlaySoundMem(this->TitleBGM, DX_PLAYTYPE_BACK);
	}

	this->startButton.DrawButton();
	this->endButton.DrawButton();

	if( repush->rePushFlg == 0 )
	{
		this->StartGame();
		this->EndGame();
	}

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
	this->LoadSounds();
	startButton.SetButtonPosition(530, 600);
	endButton.SetButtonPosition(540, 670);
	startButton.SetHitPos(395, 574, 655, 633);
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
			PlaySoundMem(ClickSE, DX_PLAYTYPE_BACK);
			StopSoundMem(TitleBGM);
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
			PlaySoundMem(ClickSE, DX_PLAYTYPE_BACK);
			GAMESTATE = GAME_END;
			StopSoundMem(TitleBGM);
			
		}
	}
}	

void TitleScene::GameEnd()
{
	static int WaitTime = 0;

	if (++WaitTime > 60)  GAMESTATE = END;
}

int TitleScene::LoadSounds()
{
	//タイトル
	if ((TitleBGM = LoadSoundMem("Assets/SHWフリー音楽素材/Title.mp3")) == -1)	return -1;
	
	//クリック音
	if ((ClickSE = LoadSoundMem("Assets/ポケットサウンド/Click.mp3")) == -1) return -1;

	return 0;
}