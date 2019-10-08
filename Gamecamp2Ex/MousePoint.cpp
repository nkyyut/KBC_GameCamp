#include "Source.h"
#include "MousePoint.h"

MousePoint::MousePoint()
{
	OldMouseInput = 0;
	NowMouseInput = 0;
}

void MousePoint::GetMouseClick()
{
	NowMouseInput = GetMouseInput();            //1�t���[���O�̏�Ԃ��N���b�N������ԂɍX�V

	//�N���b�N�����Ƃ�
	if( ( ( OldMouseInput & MOUSE_INPUT_LEFT ) != MOUSE_INPUT_LEFT )       //�P�t���[���O�͉�����ĂȂ����Ǎ��͉�����Ă�
		&& ( ( NowMouseInput & MOUSE_INPUT_LEFT ) == MOUSE_INPUT_LEFT ) )
	{
		GetMousePoint( &bmpX, &bmpY );                        //�N���b�N�����Ƃ��̍��W���i�[
		DrawFormatString( 700, 100, 0x000000, "OK" );
	}

	//�w�𗣂�����
	if( ( ( OldMouseInput & MOUSE_INPUT_LEFT ) == MOUSE_INPUT_LEFT )
		&& ( ( NowMouseInput & MOUSE_INPUT_LEFT ) != MOUSE_INPUT_LEFT ) )
	{
		GetMousePoint( &mpX, &mpY );                        //�N���b�N�����Ƃ��̍��W���i�[
		DrawFormatString( 700, 100, 0x000000, "NO" );
		killFlg = TRUE;
	}

	OldMouseInput = NowMouseInput;

}

void MousePoint::PrintMouseClick()
{
	DrawFormatString( 700, 100, 0xffffff, "%d,%d,%d,%d", bmpX, bmpY, mpX, mpY );
}