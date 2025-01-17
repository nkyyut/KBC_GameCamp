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
struct SOUND sound;
//struct PICTURE pic;

Wall *pwall;
MousePoint mPoint;
TitleScene title;
Player player;
Enemy enemy;
ResultScene result;
Repush repush;

int GAMESTATE;

static int RefreshRate = 0;

//関数宣言
//フレームレート制御関数
static bool FR_Update();
static void FR_Draw();
static void FR_Wait();

void GameInit();
void GameMain();

int LoadSounds();

//int MouseState();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	GAMESTATE = GAME_TITLE;

	ChangeWindowMode( TRUE );
	SetGraphMode( _SCREENSIZE_X, _SCREENSIZE_Y, 32 );
	SetDrawScreen( DX_SCREEN_BACK );
	SetMainWindowText("にげむしゃ");
	SetWindowIconID(333);

	if( DxLib_Init() == -1 )	return -1;

	title.Init();
	result.Init();

	if( ( LoadSounds() == -1 ) )		return -1;
	if( ( enemy.LoadImages() == -1 ) )	return -1;
	if( ( player.LoadPlayerPic() == -1 ) )	return -1;

	while( ProcessMessage() == 0 && ClearDrawScreen() == 0 && GAMESTATE != 99 )
	{

		opt.OldK = opt.NowK;
		opt.NowK = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
		opt.Kflg = opt.NowK & ~opt.OldK;

		switch( GAMESTATE )
		{
			case GAME_TITLE:
				title.DrawTitle( &repush );
				break;

			case GAME_INIT:
				GameInit();
				break;

			case GAME_MAIN:
				GameMain();
				break;

			case GAME_WIN:
				result.DrawResult( &repush );
				break;

			case GAME_END:
				GAMESTATE = 99;
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
	//DrawFormatString( 0, 0, 0xff0000, "%.1f", FR_Control.mFps );

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
	if( CheckSoundMem( sound.mainBGM ) == 0 )
	{
		PlaySoundMem( sound.mainBGM, DX_PLAYTYPE_BACK );
	}

	//mPoint.PrintMouseClick();
	enemy.BackScrool( player.playerLife, player.WaitTimer, player.GoalDist);
	//DrawStage();
	DrawWall();
	player.DrawPlayer();
	enemy.DrawEnemy();
	DrawUI( player.GoalDist );
	

	if( player.GoalDist++ >= _GAMECLEARTIME_ )
	{
		mPoint.mpInit();
		enemy.eInit();
		player.pInit();
		GAMESTATE = GAME_WIN;
		StopSoundMem(sound.mainBGM);
	}

	if( mPoint.killFlg == FALSE )
	{
		mPoint.GetMouseClick( pwall );
	}

	if( mPoint.wallFlg == 1 && player.playerFlg == 0 )
	{
		player.HitPlayer( pwall );
		if( player.playerFlg == 1 )
		{
			PlaySoundMem( sound.collision, DX_PLAYTYPE_BACK );
			delete pwall;
			mPoint.i = 0;
		}
	}

	if( player.playerFlg == 1 )
	{
		player.DangerTime( &enemy, pwall, sound.collision );
	}

	if( player.pKillFlg == 2 )
	{
		delete pwall;
		mPoint.mpInit();
		enemy.eInit();
		player.pInit();
		GAMESTATE = GAME_TITLE;
		StopSoundMem(sound.mainBGM);
	}

	//DrawFormatString( 700, 130, 0x000000, "%d, %d", mPoint.bmpX, mPoint.bmpY );
	//DrawFormatString( 700, 160, 0x000000, "%d, %d", mPoint.mpX, mPoint.mpY );
	//DrawFormatString( 700, 190, 0x000000, "%d", mPoint.clickFlg );
	//DrawFormatString( 700, 220, 0x000000, "%d", player.playerLife );
}

void DrawWall()
{
	//static int i = 0;

	//壁出現までの待機時間
	if( mPoint.i != -1 &&  mPoint.i++ > 60 )
	{
		pwall = new Wall;
		mPoint.i = -1;
		mPoint.wallFlg = 1;
		if( pwall->LoadWallImages() == -1 )	GAMESTATE = GAME_END;
	}

	//壁を描画する時間

	if( mPoint.i == -1 )
	{
		//pwall->HitmouseRange();
		if( player.playerLife != 0 && ( player.WaitTimer == 0 || player.WaitTimer >= 160 ) ) {
			pwall->MoveWall(player.GoalDist);
		}
		pwall->WallDraw();

		//DrawFormatString( 700, 250, 0x000000, "%d",  pwall->WallState );

		if( pwall->ScreenOut() == 1 )
		{
			delete pwall;
			mPoint.bmpX = 0;
			mPoint.bmpY = 0;
			mPoint.mpX = 0;
			mPoint.mpY = 0;
			mPoint.clickFlg = 0;
			mPoint.i = 0;
			mPoint.killFlg = FALSE;
			mPoint.wallFlg = 0;
			pwall->WallState = 0;
		}

		if( mPoint.killFlg == TRUE )
		{
			if( mPoint.CompCoor( mPoint.bmpY, mPoint.mpY ) == TRUE )
			{
				if( mPoint.bmpY > ( pwall->y + pwall->hitFenceY ) )
				{
					if( mPoint.mpY < ( pwall->y - pwall->hitFenceY ) )
					{
						PlaySoundMem( sound.swordAttack, DX_PLAYTYPE_BACK );
						delete pwall;
						mPoint.bmpX = 0;
						mPoint.bmpY = 0;
						mPoint.mpX = 0;
						mPoint.mpY = 0;
						mPoint.clickFlg = 0;
						mPoint.i = 0;
						//mPoint.killFlg = FALSE;
						mPoint.wallFlg = 0;
						pwall->WallState = 0;
					}
				}
			}
			else if( mPoint.CompCoor( mPoint.bmpY, mPoint.mpY ) == FALSE )
			{
				if( mPoint.mpY > ( pwall->y + pwall->hitFenceY ) )
				{
					if( mPoint.bmpY < ( pwall->y - pwall->hitFenceY ) ) {
						PlaySoundMem( sound.swordAttack, DX_PLAYTYPE_BACK );
						delete pwall;
						mPoint.bmpX = 0;
						mPoint.bmpY = 0;
						mPoint.mpX = 0;
						mPoint.mpY = 0;
						mPoint.clickFlg = 0;
						mPoint.i = 0;
						//mPoint.killFlg = FALSE;
						mPoint.wallFlg = 0;
						pwall->WallState = 0;
					}
				}
			}
			mPoint.killFlg = FALSE;
		}
	}
}

int LoadSounds()
{

	if ( ( sound.mainBGM = LoadSoundMem( "Assets/sounds/mainBGM.mp3" ) ) == -1 )		return -1;
	if( ( sound.swordAttack = LoadSoundMem( "Assets/sounds/swordAttack.mp3" ) ) == -1 )	return -1;
	if( ( sound.collision = LoadSoundMem( "Assets/sounds/col.mp3" ) ) == -1 )	return -1;

	return 0;
}