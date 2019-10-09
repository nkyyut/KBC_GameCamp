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

		int WallState;	//��Ƃ��΂̕Ǎ��񂾂�����K�v���Ȃ�

	//private :
		int x;				//���肭��ǒ��S�_X
		int y;				//���肭��ǒ��S�_Y
		int moveSpeed;		//�ǂ̓������x
		int hitFenceX;		//�t�F���X�̏ꍇX
		int hitFenceY;		//�t�F���X�̏ꍇY
		int mhitWidth;		//�}�E�X�̔�������W(����)
		int mhitHeight;		//�}�E�X�̔�������W(����)
};