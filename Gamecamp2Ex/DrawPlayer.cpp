// DrawPlayerクラスの実装
#include "Source.h"
#include "Wall.h"
#include "DrawPlayer.h"

Player::Player()
{
	 playerX = 300;
	 playerY = 568;
	 playerLife = 2;
	 playerHit;
}


void Player::DrawPlayer()
{
	DrawBox(playerX, playerY, 400, 400, 0xffff00, TRUE);


}

// 壁に当たるとデンジャータイムが発生
void Player::DangerTime( Wall *pwall ){
	if ( ( pwall->x + ( pwall->hitFenceY / 2 ) ) >= playerY ) {
		if (++WaitTimer < 300)
		{
			playerLife--;	
			//enemywork++		←仮	※ここでエネミーが画面上に出てくる処理
			if ((pwall->x + (pwall->hitFenceY / 2)) >= playerY)
			{
				playerLife--;
				//if (playerLife == 0) GAMESTATE = GAME_LOSE;
			}
		}/*enemywork--;*/


	}


}



















// デンジャータイム中に壁に衝突するとゲームオーバー






// 一定時間経過後にデンジャータイム終了





// 壁に衝突すると点滅アニメーション

