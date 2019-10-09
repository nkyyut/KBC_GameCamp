#ifndef _DRAWENEMY_H_
#define _DRAWENEMY_H_

#include "DxLib.h"

class Enemy {
public:
	void DrawEnemy();
	void BackScrool();
	int LoadImages();
	void up(int hp);
private:
	int ScroolSpeed;
	int BackScreen;
	int EnemyLife;
	int x=512, y=768;

};
#endif