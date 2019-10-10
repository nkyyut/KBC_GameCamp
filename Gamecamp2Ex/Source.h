#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "DxLib.h"

#define ICON "Assets/nigemusya.icon"

//ゲームクリアまでの時間
#define _GAMECLEARTIME_ 2400

#define _FONTSIZE_S	20
#define _FONTSIZE_L	40

//フレームレート定数(触るな)
#define	_FRAMERATE_60	60
#define _FRAMERATE_144	144

#define _SCREENSIZE_X	1024
#define _SCREENSIZE_Y	768

extern int GAMESTATE;

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