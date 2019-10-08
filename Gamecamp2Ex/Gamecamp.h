#ifndef _GAMECAMP_H_
#define _GAMECAMP_H_

#include "DxLib.h"

//�t���[�����[�g�萔(�G���)
#define	_FRAMERATE_60	60
#define _FRAMERATE_144	144

//��ʃT�C�Y
#define _SCREENSIZE_X	800
#define _SCREENSIZE_Y	600

//�t�H���g�T�C�Y�w��
#define _FONTSIZE_S		12

//�Q�[���X�e�[�g
static int GAMESTATE;

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
} OPERATE;
extern struct OPERATE opt;
/*****      �摜�\����      *****/
typedef struct PICTURE
{
	int Picture;
};

/*****      �摜�\����      *****/
typedef struct SOUND
{
	int Sound;
};	//���y�\���̐錾

typedef struct HITBOX
{
	int click1;
	int click2;
};

typedef struct PLAYER
{
	int playerX;
	int playerY;
	int playerLife;
};

typedef struct ENEMY
{
	int enemyX;
	int enemyY;
};

#endif