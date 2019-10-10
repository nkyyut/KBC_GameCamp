#include "Source.h"
#include "DxLib.h"
#include "Result.h"
#include "Repush.h"

/// /// <summary>
/// ���U���g��ʂ�`�悵�܂�
/// </summary>
void ResultScene::DrawResult( Repush *repush )
{
	SetFontSize(_FONTSIZE_S);

	GetMousePoint(&this->mpX, &this->mpY);

	LoadGraphScreen(0, 0, "Assets/ResultImage.png", false);
	DrawFormatString(0, 0, 0xffffff,"%d, %d", mpX, mpY);
	this->backButton.DrawButton();
	
	if (backButton.ChackHit(this->mpX, this->mpY) == 1) {
		DrawLine(420, 660, 610, 660, 0x000000);
	}

	if (CheckSoundMem(GameClearBGM) == 0) {
		PlaySoundMem(GameClearBGM, DX_PLAYTYPE_BACK);
	}

	this->SceneBack( repush );

}

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

/// <summary>
/// ���U���g��������
/// </summary>
void ResultScene::Init()
{
	this->backButton.image = LoadGraph("Assets/backButton.png");
	this->LoadSounds();
	this->backButton.SetButtonPosition(512,635);
	this->backButton.SetHitPos(420,600,610,660);
}

/// <summary>
/// �^�C�g����ʂ֑J�ڂ��鏈��
/// �X�^�[�g�{�^���ƃ}�E�X�̓����蔻����s��
/// �}�E�X���������Ɣ�����s��
/// </summary>
void ResultScene::SceneBack( Repush *repush )
{
	int mouse = GetMouseInput();

	if (mouse && MOUSE_INPUT_LEFT) {
		if (backButton.ChackHit(mpX, mpY) == 1) {
			repush->OldK = GetMouseInput();
			repush->rePushFlg = 1;
			StopSoundMem(GameClearBGM);
			PlaySoundMem(click, DX_PLAYTYPE_BACK);
			GAMESTATE = GAME_TITLE;
		}
	}
}

int ResultScene::LoadSounds()
{
	if ((GameClearBGM = LoadSoundMem("Assets/�|�P�b�g�T�E���h/wafu-clear.mp3")) == -1) return -1;

	if ((click = LoadSoundMem("Assets/�|�P�b�g�T�E���h/Click.mp3")) == -1)  return -1;

	return 0;
}