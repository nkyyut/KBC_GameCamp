#ifndef _DRAWENEMY_H_
#define _DRAWENEMY_H_

#include "DxLib.h"

class Enemy {
public:
	void DrawEnemy();
	void BackScrool();
private:
	int ScroolSpeed;
	int BackScreen;

};
#endif