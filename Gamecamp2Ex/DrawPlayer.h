#ifndef _DRAWPLAYER_H_
#define _DRAWPLAYER_H_

#include "DxLib.h"
#include "Wall.h"
#include "DrawEnemy.h"


class Player {
public:

	int playerX;
	int playerY;
	int playerFlg;
	int WaitTimer = 0;
	int dtimeFrame = 0;
	void DrawPlayer();
	void HitPlayer( Wall *pwall );
	void DangerTime( Enemy* enemy, Wall *pwall, int colsound );
	Player();
	int playerLife;
	int GoalDist = 0;

	int playerPic;
	int LoadPlayerPic();
	int pKillFlg = 0;

	void pInit()
	{
		playerX = 1024 / 2;
		playerY = 568;
		playerFlg = 0;
		WaitTimer = 0;
		playerLife = 2;
		pKillFlg = 0;
		dtimeFrame = 0;
		GoalDist = 0;
	}

};
	
	

//PLAYER player = { 0, 0, 2 };


#endif