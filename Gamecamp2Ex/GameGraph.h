#pragma once


class GameGraph
{
public:
	GameGraph();//�R���X�g���N�^
	//~GameGraph();
	void DrawGameGraph();	//�Q�[���O���t�`��
	void Step();	//6�b��1��L��������ɂ����鏈��

	int WhiteBoxX;
	int WhiteBoxY;
	int Gole;
	int GoleStep;
	int Zibun;
	int ZibunStep;
	int Teki;
	int TekiStep;
	int StepTime;
};

