#pragma once

void DrawWall();

class Wall
{
	public :
		Wall();
		~Wall();
		void MoveWall();
		void WallDraw();
		int ScreenOut();
		
		void HitmouseRange();

	private :
		int x;				//迫りくる壁中心点X
		int y;				//迫りくる壁中心点Y
		int moveSpeed;		//壁の動く速度
		int mhitWidth;		//マウスの判定内座標(横幅)
		int mhitHeight;		//マウスの判定内座標(高さ)
};