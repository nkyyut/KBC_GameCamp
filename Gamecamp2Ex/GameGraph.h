#pragma once


class GameGraph
{
public:
	GameGraph();//コンストラクタ
	//~GameGraph();
	void DrawGameGraph();	//ゲームグラフ描画
	void Step();	//6秒に1回キャラを上にあげる処理

	int WhiteBoxX;
	int WhiteBoxY;
	int Gole;
	int GoleStep;
	int Zibun;
	int ZibunStep;
	int Teki;
	int TekiStep;
	int StepTime;
};

