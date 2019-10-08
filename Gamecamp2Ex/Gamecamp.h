#ifndef _GAMECAMP_H_
#define _GAMECAMP_H_

#include "DxLib.h"

//フレームレート定数(触るな)
#define	_FRAMERATE_60	60
#define _FRAMERATE_144	144

//画面サイズ
#define _SCREENSIZE_X	800
#define _SCREENSIZE_Y	600

//フォントサイズ指定
#define _FONTSIZE_S		12

//ゲームステート
static int GAMESTATE;

/*****      ゲームモード列挙体      *****/
typedef enum GAME_MODE
{
	GAME_TITLE,			//タイトル
	GAME_HELP,			//ヘルプ
	GAME_LEVEL,			//難易度
	GAME_INIT,			//初期化
	GAME_MAIN,			//メイン
	GAME_WIN,			//勝利画面
	GAME_LOSE,			//敗北者画面
	GAME_END,			//エンド処理
	GAME_INPUTRANKING,	//ランキング入り画面
	GAME_RANKING,		//ランキング画面
	END = 99			//エンド
};

struct OPERATE
{
	//KeyInput
	int OldK;
	int NowK;
	int Kflg;
} OPERATE;
extern struct OPERATE opt;
/*****      画像構造体      *****/
typedef struct PICTURE
{
	int Picture;
};

/*****      画像構造体      *****/
typedef struct SOUND
{
	int Sound;
};	//音楽構造体宣言

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