#include "Button.h"
#include "DxLib.h"

/// <summary>
/// �{�^���̃|�W�V������ݒ�
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
void Button::SetButtonPosition(int x, int y)
{
	this->bpX = x;
	this->bpY = y;
}

void Button::DrawButton() 
{
	DrawRotaGraph(this->bpX, this->bpY, 0.5, 0.0, this->image, TRUE, FALSE);
}

void Button::SetHitPos(int x, int y, int x2, int y2)
{
	this->HitPosX = x;
	this->HitPosX2 = x2;
	this->HitPosY = y;
	this->HitPosY2 = y2;
}

/// <summary>
/// �{�^�����������ǂ����𔻒�
/// ���肪�ʂ�ƁA1��Ԃ�
/// </summary>
/// <param name="x">�}�E�X����X���W</param>
/// <param name="y">�}�E�X����Y���W</param>
/// <returns>���肪�ʂ� = 1�A���肪�ʂ�Ȃ� = 0</returns>
int Button::ChackHit(int x, int y)
{
	if (x > this->HitPosX && y > this->HitPosY){
		if (x < this->HitPosX2 && y < this->HitPosY2) {
			return 1;
		}
	}

	return 0;
}

Button::Button()
{
}

Button::~Button()
{
}