// DrawPlayer�N���X�̎���
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

// �ǂɓ�����ƃf���W���[�^�C��������
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




// �ǂɏՓ˂���Ɠ_�ŃA�j���[�V����


















// �f���W���[�^�C�����ɕǂɏՓ˂���ƃQ�[���I�[�o�[






// ��莞�Ԍo�ߌ�Ƀf���W���[�^�C���I��







