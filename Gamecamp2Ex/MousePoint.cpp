#include "Source.h"
#include "MousePoint.h"

MousePoint::MousePoint()
{
	OldMouseInput = 0;
	NowMouseInput = 0;
}

void MousePoint::GetMouseClick()
{
	NowMouseInput = GetMouseInput();            //1フレーム前の状態をクリックした状態に更新

	//クリックしたとき
	if( ( ( OldMouseInput & MOUSE_INPUT_LEFT ) != MOUSE_INPUT_LEFT )       //１フレーム前は押されてないけど今は押されてる
		&& ( ( NowMouseInput & MOUSE_INPUT_LEFT ) == MOUSE_INPUT_LEFT ) )
	{
		GetMousePoint( &bmpX, &bmpY );                        //クリックしたときの座標を格納
		DrawFormatString( 700, 100, 0x000000, "OK" );
	}

	//指を離した時
	if( ( ( OldMouseInput & MOUSE_INPUT_LEFT ) == MOUSE_INPUT_LEFT )
		&& ( ( NowMouseInput & MOUSE_INPUT_LEFT ) != MOUSE_INPUT_LEFT ) )
	{
		GetMousePoint( &mpX, &mpY );                        //クリックしたときの座標を格納
		DrawFormatString( 700, 100, 0x000000, "NO" );
		killFlg = TRUE;
	}

	OldMouseInput = NowMouseInput;

}

void MousePoint::PrintMouseClick()
{
	DrawFormatString( 700, 100, 0xffffff, "%d,%d,%d,%d", bmpX, bmpY, mpX, mpY );
}