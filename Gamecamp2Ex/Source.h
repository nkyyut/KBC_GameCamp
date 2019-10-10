#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "DxLib.h"

#define ICON "Assets/nigemusya.icon"

//�Q�[���N���A�܂ł̎���
#define _GAMECLEARTIME_ 2400

#define _FONTSIZE_S	20
#define _FONTSIZE_L	40

//�t���[�����[�g�萔(�G���)
#define	_FRAMERATE_60	60
#define _FRAMERATE_144	144

#define _SCREENSIZE_X	1024
#define _SCREENSIZE_Y	768

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

struct PICTRUE
{
	int Gage;
};
extern struct PICTURE pic;

struct SOUND
{
	int mainBGM;
	int swordAttack;
	int collision;
};

extern struct SOUND sound;