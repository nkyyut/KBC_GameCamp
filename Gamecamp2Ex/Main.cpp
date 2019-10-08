//#include "DxLib.h"
//
//#include "Drawtitle.h"
//#include "DrawWall.h"
//#include "DrawEnemy.h"
//#include "DrawPlayer.h"
//#include "DrawStage.h"
//#include "DrawUI.h"
//#include "DrawWin.h"
//#include "DrawLose.h"

#include "Main.h"

//�t���[�����[�g�n�ϐ�
static int RefreshRate;

/*****      �t���[�����[�g�\����      *****/
typedef struct FRAMERATE_CONTROL
{
	int mStartTime;
	int mCount;
	float mFps;
	int ReFreshRateState;
};
FRAMERATE_CONTROL FR_Control = { 0, 0, 0.0, 0 };	//�t���[�����[�g����\���̐錾

struct OPERATE opt;
PICTURE Pic;	//�摜�\���̐錾
SOUND Sound;
HITBOX	hitbox = { 0, 0 };
PLAYER player = { 0, 0, 2 };
ENEMY enemy = { 0, 0 };

//�֐��錾

//�t���[�����[�g����֐�
static bool FR_Update();
static void FR_Draw();
static void FR_Wait();

void GameInit();
void GameMain();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	GAMESTATE = GAME_TITLE;
	SetMainWindowText( "X" );
	ChangeWindowMode( TRUE );
	SetWindowSize( 1280, 800 );

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
				DrawWin();
				break;

			case GAME_LOSE:
				DrawLose();
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

	DrawStage();
	DrawWall();

	DrawPlayer();
	DrawEnemy();

	DrawUI();

}