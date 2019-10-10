#pragma once

class Button
{
public:
	Button();
	~Button();	
	void SetButtonPosition(int x, int Y);
	void DrawButton();
	void SetHitPos(int x, int y, int x2, int y2);
	int ChackHit(int x, int y);
	int image;
private:
	int bpX;
	int bpY;
	int HitPosX;
	int HitPosY;
	int HitPosX2;
	int HitPosY2;
};