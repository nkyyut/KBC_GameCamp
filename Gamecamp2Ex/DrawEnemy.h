#ifndef _DRAWENEMY_H_
#define _DRAWENEMY_H_

#include "DxLib.h"

class Enemy {
	private:
		int ScroolSpeed;
		int BackScreen;
		int EnemyLife;
		int x = 512, y = 768;

	public:
		void DrawEnemy();
		void BackScrool( int waittime );
		int LoadImages();
		void up( int hp, int *pkillflg, int waittime );
		int animFrame = 0;

		void eInit()
		{
			ScroolSpeed = 0;
			EnemyLife = 0;
			x = 512;
			y = 768;
		}

};
#endif