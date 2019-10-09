#include "Source.h"

#include "ReadHeader.h"

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
//struct PICTURE pic;

Wall *pwall;
MousePoint mPoint;

int GAMESTATE;

static int RefreshRate = 0;

//関数宣言
//フレームレート制御関数
static bool FR_Update();
static void FR_Draw();
static void FR_Wait();

void GameInit();
void GameMain();

//int MouseState();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	GAMESTATE = GAME_TITLE;

	ChangeWindowMode( TRUE );
	SetGraphMode( _SCREENSIZE_X, _SCREENSIZE_Y, 32 );
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
	
	//mPoint.PrintMouseClick();
	DrawStage();
	DrawUI();
	DrawWall();
	if( mPoint.killFlg == FALSE )
	{
		mPoint.GetMouseClick( pwall );
	}

	DrawFormatString( 700, 130, 0x000000, "%d, %d", mPoint.bmpX, mPoint.bmpY );
	DrawFormatString( 700, 160, 0x000000, "%d, %d", mPoint.mpX, mPoint.mpY );
	DrawFormatString( 700, 190, 0x000000, "%d", mPoint.clickFlg );
	DrawFormatString( 700, 220, 0x000000, "%d", mPoint.killFlg );
}

//int MouseState()
//{
//	int beforemouseInput = 0;
//	int nowmouseInput = GetMouseInput();
//
//	if( beforemouseInput & MOUSE_INPUT_LEFT ) 
//	{
//		//左クリック
//		return 1;
//	}
//
//	return 0;
//}

void DrawWall()
{
	static int i = 0;

	//壁出現までの待機時間
	if( i != -1 &&  i++ > 60 )
	{
		pwall = new Wall;
		i = -1;
	}

	//壁を描画する時間
	if( i == -1 )
	{
		pwall->HitmouseRange();
		pwall->MoveWall();
		pwall->WallDraw();

		if( pwall->ScreenOut() == 1 )
		{
			delete pwall;
			mPoint.bmpX = 0;
			mPoint.bmpY = 0;
			mPoint.mpX = 0;
			mPoint.mpY = 0;
			mPoint.clickFlg = 0;
			i = 0;
			mPoint.killFlg = FALSE;
		}

		if( mPoint.killFlg == TRUE )
		{
			if( mPoint.CompCoor( mPoint.bmpY, mPoint.mpY ) == TRUE )
			{
				if( mPoint.bmpY > ( pwall->y + pwall->hitFenceY ) )
				{
					delete pwall;
					mPoint.bmpX = 0;
					mPoint.bmpY = 0;
					mPoint.mpX = 0;
					mPoint.mpY = 0;
					mPoint.clickFlg = 0;
					i = 0;
					//mPoint.killFlg = FALSE;
				}
			}
			else if( mPoint.CompCoor( mPoint.bmpY, mPoint.mpY ) == FALSE )
			{
				if( mPoint.mpY > ( pwall->y + pwall->hitFenceY ) )
				{
					delete pwall;
					mPoint.bmpX = 0;
					mPoint.bmpY = 0;
					mPoint.mpX = 0;
					mPoint.mpY = 0;
					mPoint.clickFlg = 0;
					i = 0;
					//mPoint.killFlg = FALSE;
				}
			}
			mPoint.killFlg = FALSE;
			//if( pwall->RectAndLine(
			//	pwall->x + pwall->hitFenceX / 2, pwall->x - pwall->hitFenceX / 2,
			//	pwall->y - pwall->hitFenceY / 2, pwall->y + pwall->hitFenceY / 2,
			//	mPoint.bmpX, mPoint.bmpY, mPoint.mpX, mPoint.mpY ) == TRUE )
			//{
			//	DrawFormatString( 700, 250, 0x000000, "●" );
			//	delete pwall;
			//	mPoint.bmpX = 0;
			//	mPoint.bmpY = 0;
			//	mPoint.mpX = 0;
			//	mPoint.mpY = 0;
			//	mPoint.clickFlg = 0;
			//	i = 0;
			//	mPoint.killFlg = FALSE;
			//}
			//delete pwall;
			//mPoint.bmpX = 0;
			//mPoint.bmpY = 0;
			//mPoint.mpX = 0;
			//mPoint.mpY = 0;
			//mPoint.clickFlg = 0;
			//i = 0;
			//mPoint.killFlg = FALSE;
		}
	}
}