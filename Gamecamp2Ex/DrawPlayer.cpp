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
	DrawRotaGraph( playerX, playerY, 0.5f, 0, playerPic, TRUE );

}

int Player::LoadPlayerPic()
{
	if( ( playerPic = LoadGraph( "Assets/uma1.png" ) ) == -1 )	return -1;
}

void Player::HitPlayer( Wall *pwall ) {

	if ( pwall->WallState == 0 && ( (pwall->y + (pwall->hitFenceY / 2)) >= playerY - 168 ) )
	{
		playerLife--;
		playerFlg = 1;
		pwall->WallState = 1;
		//if (playerLife == 0) GAMESTATE = GAME_LOSE;
	}
}

// �ǂɓ�����ƃf���W���[�^�C��������
void Player::DangerTime( Enemy* enemy, Wall *pwall ) {
	if( ++WaitTimer < 1200 )
	{
		//if( ++dtimeFrame < 160 )
		//{
			HitPlayer( pwall );
			if( pKillFlg == 0 && playerLife == 0 )
			{
				pKillFlg = 1;
			}
		//}
		else if( dtimeFrame >= 160 )
		{

		}
	}
	else if( /*pKillFlg == 0 && */WaitTimer == 1201 )
	{
		playerFlg = 0;
		playerLife = 2;
		WaitTimer = 0;
	}

	DrawFormatString( 700, 280, 0x000000, "%d", WaitTimer );
	DrawFormatString( 700, 310, 0x000000, "%d", pKillFlg );
	enemy->up( playerLife, &pKillFlg, this->WaitTimer );
}



















// �f���W���[�^�C�����ɕǂɏՓ˂���ƃQ�[���I�[�o�[






// ��莞�Ԍo�ߌ�Ƀf���W���[�^�C���I��





// �ǂɏՓ˂���Ɠ_�ŃA�j���[�V����

