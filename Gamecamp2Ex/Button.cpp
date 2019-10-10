#include "Button.h"
#include "DxLib.h"

/// <summary>
/// ボタンのポジションを設定
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
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
/// ボタンを押したどうかを判定
/// 判定が通ると、1を返す
/// </summary>
/// <param name="x">マウス側のX座標</param>
/// <param name="y">マウス側のY座標</param>
/// <returns>判定が通る = 1、判定が通らない = 0</returns>
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