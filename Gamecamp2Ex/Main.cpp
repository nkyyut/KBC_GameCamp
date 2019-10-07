#include "DxLib.h"
#include "Gamecamp.h"
#include "Drawtitle.h"

static int GAMESTATE;

//�t���[�����[�g�n�ϐ�
static int RefreshRate;

//�t���[�����[�g�萔( 60 )
//#define	_FRAMERATE_60	60
//#define _FRAMERATE_144	144
//
//#define _SCREENSIZE_X	800
//#define _SCREENSIZE_Y	600
//
//#define _FONTSIZE_S		12

/*****      �Q�[�����[�h�񋓑�      *****/
//typedef enum GAME_MODE
//{
//	GAME_TITLE,			//�^�C�g��
//	GAME_HELP,			//�w���v
//	GAME_LEVEL,			//��Փx
//	GAME_INIT,			//������
//	GAME_MAIN,			//���C��
//	GAME_WIN,			//�������
//	GAME_LOSE,			//�s�k�҉��
//	GAME_END,			//�G���h����
//	GAME_INPUTRANKING,	//�����L���O������
//	GAME_RANKING,		//�����L���O���
//	END = 99			//�G���h
//};

/*****      �L�[����\����      *****/
//typedef struct OPERATE
//{
//	KeyInput
//	int OldK;
//	int NowK;
//	int Kflg;
//} OPERATE;
//
//extern OPERATE opt;
//
///*****      �摜�\����      *****/
//typedef struct PICTURE
//{
//	int Picture;
//};
//PICTURE Pic;	//�摜�\���̐錾
//
///*****      �摜�\����      *****/
//typedef struct SOUND
//{
//	int Sound;
//};
//SOUND Sound;		//���y�\���̐錾
//
//typedef struct HITBOX
//{
//	int click1;
//	int click2;
//};
//
//HITBOX	hitbox = { 0, 0 };
//
//typedef struct PLAYER
//{
//	int playerX;
//	int playerY;
//	int playerLife;
//};
//PLAYER player = { 0, 0, 2 };
//
//typedef struct ENEMY
//{
//	int enemyX;
//	int enemyY;
//};
//ENEMY enemy = { 0, 0 };

/*****      �t���[�����[�g�\����      *****/
typedef struct FRAMERATE_CONTROL
{
	int mStartTime;
	int mCount;
	float mFps;
	int ReFreshRateState;
};
FRAMERATE_CONTROL FR_Control = { 0, 0, 0.0, 0 };	//�t���[�����[�g����\���̐錾

//�֐��錾

//�t���[�����[�g����֐�
static bool FR_Update();
static void FR_Draw();
static void FR_Wait();

//void DrawTitle();
void GameInit();
void GameMain();

void DrawStage();
void DrawPlayer();
void DrawEnemy();
void DrawUI();

void DrawWin();
void DrawLose();

void DrawWall();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	GAMESTATE = GAME_TITLE;
	SetMainWindowText( "X" );

	if( DxLib_Init() == -1 )	return -1;

	while( ProcessMessage() == 0 && ClearDrawScreen() == 0 && GAMESTATE != 99 )
	{

		opt.OldK = opt.NowK;
		opt.NowK = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
		opt.Kflg = opt.NowK & ~opt.OldK;

		switch( GAMESTATE )
		{

			case GAME_TITLE:
				DrawTitle();
				break;
			case GAME_HELP:
				break;
			case GAME_INIT:
				GameInit();
				break;
			case GAME_MAIN:
				GameMain();
				break;
			case GAME_WIN:
				
				break;
			case GAME_LOSE:
				break;
			case GAME_END:
				break;

		}

		FR_Update();
#ifdef _DEBUGMODE
		FR_Draw();
#endif
		ScreenFlip();
		FR_Wait();

	}

	DxLib_End();
	return 0;

}

/******�@�@�@�@�@�@�@�t���[��������֐�         ******/
static bool FR_Update()
{
	if( FR_Control.mCount == 0 )
	{
		FR_Control.mStartTime = GetNowCount();
	}
	if( FR_Control.mCount == RefreshRate )
	{
		int t = GetNowCount();
		FR_Control.mFps = 1000.f / ( ( t - FR_Control.mStartTime ) / ( float )RefreshRate );
		FR_Control.mCount = 0;
		FR_Control.mStartTime = t;
	}
	FR_Control.mCount++;
	return true;
}

/******�@�@�@�@�@�@�@�t���[�����[�g�`��         ******/
static void FR_Draw()
{

	SetFontSize( _FONTSIZE_S );
	SetFontSize( _FONTSIZE_S );
	DrawFormatString( 0, 0, 0xff0000, "%.1f", FR_Control.mFps );

}

/******�@�@�@�@�@�@�@ �����҂��֐�          ******/
static void FR_Wait()
{
	int tookTime = GetNowCount() - FR_Control.mStartTime;
	int waitTime = FR_Control.mCount * 1000 / _FRAMERATE_60 - tookTime;

	if( waitTime > 0 )
	{
		Sleep( waitTime );
	}
}

void GameInit()
{
	GAMESTATE = GAME_MAIN;
}

void GameMain()
{
	
}

void DrawStage()
{

}

void DrawPlayer()
{

}

void DrawEnemy()
{

}

void DrawUI()
{

}

void DrawWall()
{

}

void DrawWin()
{

}

void DrawLose()
{

}