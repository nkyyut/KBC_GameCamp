// DrawPlayer�N���X�̎���
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

// �ǂɓ�����ƃf���W���[�^�C��������
void Player::DangerTime( Wall *pwall ){
	if ( ( pwall->x + ( pwall->hitFenceY / 2 ) ) >= playerY ) {
		if (++WaitTimer < 300)
		{
			playerLife--;	
			//enemywork++		����	�������ŃG�l�~�[����ʏ�ɏo�Ă��鏈��
			if ((pwall->x + (pwall->hitFenceY / 2)) >= playerY)
			{
				playerLife--;
				//if (playerLife == 0) GAMESTATE = GAME_LOSE;
			}
		}/*enemywork--;*/


	}


}



















// �f���W���[�^�C�����ɕǂɏՓ˂���ƃQ�[���I�[�o�[






// ��莞�Ԍo�ߌ�Ƀf���W���[�^�C���I��





// �ǂɏՓ˂���Ɠ_�ŃA�j���[�V����

