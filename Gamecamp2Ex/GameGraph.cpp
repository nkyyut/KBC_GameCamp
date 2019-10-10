#include "GameGraph.h"
#include"Source.h"

GameGraph::GameGraph() {
	Gole = 0;
	GoleStep = 7;
	Zibun = 0;
	ZibunStep = 2;
	Teki = 0;
	TekiStep = 1;
	StepTime = 0;
	WhiteBoxX = (324 / 2);	//162
	WhiteBoxY = (768 / 2);	//384
}

void GameGraph::DrawGameGraph() {

	//ゲーム画面の白いとこの真ん中にボックスを作る
	//白いとこの大きさは横：1024-700、縦は768-0
	//ゲームグラフは仮で縦70×横10なので
	DrawBox(WhiteBoxX - 5,WhiteBoxY -35,
			WhiteBoxX + 5,WhiteBoxY + 35, 0xffff00, TRUE);
	//ゴールのボックス表示（画像に切り替える）
	Gole = DrawBox(WhiteBoxX - 5, WhiteBoxY - (10*GoleStep+10), 
			WhiteBoxX + 5, WhiteBoxY - (10*GoleStep), 0xff0000, TRUE);
	//敵のボックス表示（画像に切り替える）
	Teki = DrawBox(WhiteBoxX - 5, WhiteBoxY + 25, 
			WhiteBoxX + 5,WhiteBoxY + 35, 0x0000ff, TRUE);
	//プレイヤーのボックス表示（画像に切り替える）
	Zibun = DrawBox(WhiteBoxX - 5, WhiteBoxY + 15, 
			WhiteBoxX + 5, WhiteBoxY + 25, 0x00ff00, TRUE);

}

//void GameGraph::Step() {
//	if (++StepTime == 360) {
//		ZibunStep++;
//		TekiStep++;
//	}StepTime = 0;
//}
