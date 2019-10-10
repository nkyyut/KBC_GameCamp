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
	DrawRotaGraph( playerX, playerY, 1.0f, 0, playerPic, TRUE );

}

int Player::LoadPlayerPic()
{
	if( ( playerPic = LoadGraph( "Assets/uma1.png" ) ) == -1 )	return -1;
}

void Player::HitPlayer( Wall *pwall ) {

	if ((pwall->y + (pwall->hitFenceY / 2)) >= playerY - 168 )
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



















// デンジャータイム中に壁に衝突するとゲームオーバー






// 一定時間経過後にデンジャータイム終了





// 壁に衝突すると点滅アニメーション

