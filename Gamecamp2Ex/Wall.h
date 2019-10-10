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

		int WallState;	//�����������������ĂȂ���

		int LoadWallImages();
		int WallImage;

	//private :
		int x;				//���肭��ǒ��S�_X
		int y;				//���肭��ǒ��S�_Y
		int moveSpeed;		//�ǂ̓������x
		int hitFenceX;		//�t�F���X�̏ꍇX
		int hitFenceY;		//�t�F���X�̏ꍇY
		int mhitWidth;		//�}�E�X�̔�������W(����)
		int mhitHeight;		//�}�E�X�̔�������W(����)
};