#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "DxLib.h"

#define _FONTSIZE_S	20

//�t���[�����[�g�萔(�G���)
#define	_FRAMERATE_60	60
#define _FRAMERATE_144	144

extern int GAMESTATE;

/*****      �Q�[�����[�h�񋓑�      *****/
typedef enum GAME_MODE
{
	GAME_TITLE,			//�^�C�g��
	GAME_HELP,			//�w���v
	GAME_LEVEL,			//��Փx
	GAME_INIT,			//������
	GAME_MAIN,			//���C��
	GAME_WIN,			//�������
	GAME_LOSE,			//�s�k�҉��
	GAME_END,			//�G���h����
	GAME_INPUTRANKING,	//�����L���O������
	GAME_RANKING,		//�����L���O���
	END = 99			//�G���h
};

struct OPERATE
{
	//KeyInput
	int OldK;
	int NowK;
	int Kflg;
};
extern struct OPERATE opt;