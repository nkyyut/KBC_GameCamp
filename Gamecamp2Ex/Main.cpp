#include "Source.h"
#include "DrawTitle.h"

/*****      フレームレート構造体      *****/
typedef struct FRAMERATE_CONTROL
{
	int mStartTime;
	int mCount;
	float mFps;
	int ReFreshRateState;
};
FRAMERATE_CONTROL FR_Control = { 0, 0, 0.0, 0 };	//フレームレート制御構造体宣言

struct OPERATE opt;

int GAMESTATE;

static int RefreshRate = 0;

//関数宣言
//フレームレート制御関数
static bool FR_Update();
static void FR_Draw();
static void FR_Wait();

void GameInit();
void GameMain();

void DrawStage();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	GAMESTATE = GAME_TITLE;

	ChangeWindowMode( TRUE );
	SetGraphMode( 640, 480, 32 );
	SetDrawScreen( DX_SCREEN_BACK );

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

			case GAME_INIT:
				GameInit();
				break;

			case GAME_MAIN:
				GameMain();
				break;

			case GAME_END:
				break;
		}

		FR_Update();
		FR_Draw();

		ScreenFlip();

		FR_Wait();
	}

	DxLib_End();
	return 0;
}

/******　　　　　　　フレーム数制御関数         ******/
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

/******　　　　　　　フレームレート描画         ******/
static void FR_Draw()
{

	SetFontSize( _FONTSIZE_S );
	SetFontSize( _FONTSIZE_S );
	DrawFormatString( 0, 0, 0xff0000, "%.1f", FR_Control.mFps );

}

/******　　　　　　　 処理待ち関数          ******/
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
}