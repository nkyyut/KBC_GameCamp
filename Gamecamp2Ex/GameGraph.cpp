#include "GameGraph.h"
#include"Source.h"

GameGraph::GameGraph() {
	Gole = 0;
	GoleStep = 7;
	Zibun = 0;
	ZibunStep = 2;
	Teki = 0;
	TekiStep = 1;
	StepTime = 0;
	WhiteBoxX = (324 / 2);	//162
	WhiteBoxY = (768 / 2);	//384
}

void GameGraph::DrawGameGraph() {

	//�Q�[����ʂ̔����Ƃ��̐^�񒆂Ƀ{�b�N�X�����
	//�����Ƃ��̑傫���͉��F1024-700�A�c��768-0
	//�Q�[���O���t�͉��ŏc70�~��10�Ȃ̂�
	DrawBox(WhiteBoxX - 5,WhiteBoxY -35,
			WhiteBoxX + 5,WhiteBoxY + 35, 0xffff00, TRUE);
	//�S�[���̃{�b�N�X�\���i�摜�ɐ؂�ւ���j
	Gole = DrawBox(WhiteBoxX - 5, WhiteBoxY - (10*GoleStep+10), 
			WhiteBoxX + 5, WhiteBoxY - (10*GoleStep), 0xff0000, TRUE);
	//�G�̃{�b�N�X�\���i�摜�ɐ؂�ւ���j
	Teki = DrawBox(WhiteBoxX - 5, WhiteBoxY + 25, 
			WhiteBoxX + 5,WhiteBoxY + 35, 0x0000ff, TRUE);
	//�v���C���[�̃{�b�N�X�\���i�摜�ɐ؂�ւ���j
	Zibun = DrawBox(WhiteBoxX - 5, WhiteBoxY + 15, 
			WhiteBoxX + 5, WhiteBoxY + 25, 0x00ff00, TRUE);

}

//void GameGraph::Step() {
//	if (++StepTime == 360) {
//		ZibunStep++;
//		TekiStep++;
//	}StepTime = 0;
//}
