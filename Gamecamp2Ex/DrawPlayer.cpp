// DrawPlayerクラスの実装
#include "Source.h"
#include "Wall.h"
#include "DrawPlayer.h"
#include "DrawEnemy.h"

Player::Player()
{
	 playerX = 300;
	 playerY = 568;
	 playerLife = 2;
	 playerFlg = 0;
}


void Player::DrawPlayer()
{
	DrawBox(playerX, playerY, 400, 400, 0xff0000, TRUE);
	DrawCircle(300, 568, 3, 0xff00ff, 1);


}

void Player::HitPlayer( Wall *pwall ) {

	if ((pwall->y + (pwall->hitFenceY / 2)) >= playerY)
	{	
	
		playerLife--;
		playerFlg = 1;


	
				

		if (playerLife == 0) GAMESTATE = GAME_LOSE;
	}
	
}

// 壁に当たるとデンジャータイムが発生
void Player::DangerTime(Enemy* enemy, Wall *pwall) {
	if (++WaitTimer < 300)
	{
		//playerLife--;	
		enemy->up(playerLife);
	}
}


void Player::FrashAnimation() {

	if (AnimationTime < 180) {
	
		if (AnimationTime % 2 == 0) {
			AnimationTime++;
			DrawBox(playerX, playerY, 400, 400, 0xffffff, TRUE);
		}

	}
	else if (AnimationTime > 180) {
		AnimationTime = 0;
	}




// 壁に衝突すると点滅アニメーション


















// デンジャータイム中に壁に衝突するとゲームオーバー






// 一定時間経過後にデンジャータイム終了







