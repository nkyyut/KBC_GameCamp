#include "Source.h"
#include "DrawEnemy.h"
#include "Wall.h"


void DrawEnemy()
{
	
}

void EnemyControl()
{
	
}

void BackScrool()
{
	ScroolSpeed +=4;

	//�X�e�[�W�摜�\��

	//�`��\�G���A��ݒ�
	SetDrawArea(0, 0, 1024, 768);

	DrawGraph(0, ScroolSpeed % 768 - 768, BackScreen, FALSE);

	DrawGraph(0, ScroolSpeed % 768, BackScreen, FALSE);

	//�G���A��߂�
	SetDrawArea(0, 0, 1024, 768);
}