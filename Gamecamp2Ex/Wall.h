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
		int x;				//���肭��ǒ��S�_X
		int y;				//���肭��ǒ��S�_Y
		int moveSpeed;		//�ǂ̓������x
		int mhitWidth;		//�}�E�X�̔�������W(����)
		int mhitHeight;		//�}�E�X�̔�������W(����)
};