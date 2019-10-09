// DrawPlayerクラスの実装
#include "Source.h"

#include "DrawPlayer.h"

Player::Player()
{
	int playerX = 350;
	int playerY = 568;
	int playerLife = 2;
	int playerHit;
}



// 壁に当たるとデンジャータイムが発生
void Player::DrawPlayer()
{
	DrawBox(playerX, playerY, 450, 368, 0xfffff, TRUE);


}





















// デンジャータイム中に壁に衝突するとゲームオーバー






// 一定時間経過後にデンジャータイム終了





// 壁に衝突すると点滅アニメーション

