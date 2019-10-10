#include "Source.h"
#include "DrawTitle.h"
#include "DxLib.h"

/// <summary>
/// �^�C�g����ʂ�`�悵�܂�
/// </summary>
void TitleScene::DrawTitle() 
{
	SetFontSize( _FONTSIZE_S );

	GetMousePoint(&this->mpX, &this->mpY);

	LoadGraphScreen(0,0, "Assets/TitleImage.png", false);
	this->startButton.DrawButton();
	this->endButton.DrawButton();

	if (CheckSoundMem(TitleBGM) == 0) {
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_BACK);
	}

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
/// �^�C�g����������
/// </summary>
void TitleScene::Init() 
{
	this->startButton.image = LoadGraph("Assets/startButtom.png");
	this->endButton.image = LoadGraph("Assets/endButton.png");
	this->LoadSounds();
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
			PlaySoundMem(ClickSE, DX_PLAYTYPE_BACK);
			StopSoundMem(TitleBGM);
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
	//�^�C�g��
	if ((TitleBGM = LoadSoundMem("Assets/SHW�t���[���y�f��/Title.mp3")) == -1) return -1;
	
	//�N���b�N��
	if ((ClickSE = LoadSoundMem("Assets/�|�P�b�g�T�E���h/Click.mp3")) == -1) return -1;

	return 0;
}