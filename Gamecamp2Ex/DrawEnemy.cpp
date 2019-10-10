#include "Source.h"
#include "DrawEnemy.h"
#include "DxLib.h"


void Enemy::DrawEnemy()
{
	EnemyLife = 2;
	//DrawLine(0,300,600,300,0xffffff);
	DrawBox(x,y,x+50,y+50,0xffffff,true);
}

void Enemy::BackScrool()
{
	ScroolSpeed +=4;

	//ステージ画像表示


	//描画可能エリアを設定
	SetDrawArea(0, 0, 1024, 768);

	DrawGraph(0, ScroolSpeed % 768 - 768, BackScreen, FALSE);

	DrawGraph(0, ScroolSpeed % 768, BackScreen, FALSE);

	//エリアを戻す
	SetDrawArea(0, 0, 1024, 768);
}

int Enemy::LoadImages()
{
	if((BackScreen=LoadGraph("Picture/Senjou.png")) == -1) return -1;

	return 0;
}

void Enemy::up(int hp)
{
	if (hp == 1)
	{
		
		
		if (y >= 576)
		{
			y -= 2;
		}
	}

	if (hp == 0) {
		
		if(y>=384){
			y -= 2;
		}
		
	}
}