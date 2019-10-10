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
	void DrawPlayer();
	void HitPlayer( Wall *pwall );
	void DangerTime(Enemy* enemy, Wall *pwall );
	Player();
	int playerLife;
	int AnimationTime = 0;
	void FrashAnimation();

	int playerPic;
	int LoadPlayerPic();



};
	
	

//PLAYER player = { 0, 0, 2 };


#endif