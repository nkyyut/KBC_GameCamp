#ifndef _DRAWPLAYER_H_
#define _DRAWPLAYER_H_

#include "DxLib.h"
#include "Wall.h"


class Player {
private:

	int playerX;
	int playerY;
	int playerLife;
	int playerHit;
	int WaitTimer = 0;
public:
	void DrawPlayer();
	void DangerTime( Wall *pwall );
	Player();



};
	
	

//PLAYER player = { 0, 0, 2 };


#endif