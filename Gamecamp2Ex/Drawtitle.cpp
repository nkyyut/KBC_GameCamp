#include "Source.h"
#include "DrawTitle.h"
#include "Repush.h"
#include "DxLib.h"

/// <summary>
/// �^�C�g����ʂ�`�悵�܂�
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

	
	GetMousePoint( &this->mpX, &this->mpY );

	LoadGraphScreen(0,0, "Assets/TitleImage.png", false);
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
/// �^�C�g����������
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
/// �Q�[���̃X�^�[�g����
/// �X�^�[�g�{�^���ƃ}�E�X�̓����蔻����s��
/// �}�E�X���������Ɣ�����s��
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
/// �Q�[���̃G���h����
/// �G���h�{�^���ƃ}�E�X�̓����蔻����s��
/// �}�E�X���������Ɣ�����s��
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