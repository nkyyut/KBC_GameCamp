#include "Source.h"
#include "DrawEnemy.h"
#include "Wall.h"


void DrawEnemy()
{
	
}

void EnemyControl()
{
	
}

void BackScrool()
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