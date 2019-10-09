#ifndef _DRAWPLAYER_H_
#define _DRAWPLAYER_H_

#include "DxLib.h"


class Player {
private:

	int playerX;
	int playerY;
	int playerLife;
	int playerHit;

public:
	void DrawPlayer();
	void Danger();
	Player();



};
	
	

//PLAYER player = { 0, 0, 2 };


#endif