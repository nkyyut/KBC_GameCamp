#pragma once

void DrawWall();

class Wall
{
	public :
		Wall();
		~Wall();
		void MoveWall();
		void WallDraw();
//		int BreakWall( MousePoint *mPoint );
		int ScreenOut();
		
		void HitmouseRange();
		bool LineAndLine( int A1x, int A1y, int A2x, int A2y, int B1x, int B1y, int B2x, int B2y );
		bool RectAndLine( int right, int left, int top, int bottom, int x1, int y1, int x2, int y2 );

		int WallState;	//当たったか当たってないか

		int LoadWallImages();
		int WallImage;

	//private :
		int x;				//迫りくる壁中心点X
		int y;				//迫りくる壁中心点Y
		int moveSpeed;		//壁の動く速度
		int hitFenceX;		//フェンスの場合X
		int hitFenceY;		//フェンスの場合Y
		int mhitWidth;		//マウスの判定内座標(横幅)
		int mhitHeight;		//マウスの判定内座標(高さ)
};