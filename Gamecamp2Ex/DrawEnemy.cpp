#include "Source.h"
#include "DrawEnemy.h"
#include "DxLib.h"


void Enemy::DrawEnemy()
{
	EnemyLife = 2;
	//DrawLine(0,300,600,300,0xffffff);
	//DrawBox(x,y,x+50,y+50,0xffffff,true);
	DrawRotaGraph( this->x, this->y, 0.7f, 0, this->EnemyPic, TRUE );
}

void Enemy::BackScrool( int plife, int waittime, int nowtime)
{
	if( plife != 0 && ( waittime == 0 || waittime >= 160 ) )
	{
		ScroolSpeed += 5 + (nowtime / 600);
	}

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
	if((BackScreen=LoadGraph("Assets/Senjou.png")) == -1) return -1;
	if( ( EnemyPic = LoadGraph( "Assets/teki1.png" ) ) == -1 )	return -1;

	return 0;
}

void Enemy::up( int hp, int *pkillflg, int waittime )
{
	if (hp == 1)
	{
		if ( waittime >= 0 && waittime < 60 )
		{	
			y -= 1;
		}
		else if( waittime >= 1000 )
		{
			y += 3;
		}
		//else if( animFrame >= 260 )
		//{
		//	animFrame = 0;
		//}
	}

	if ( hp == 0 ) {
		if( y > 500 ){
			y -= 5;
		}
		else if( y <= 500 )
		{
			*pkillflg = 2;
		}
	}

}