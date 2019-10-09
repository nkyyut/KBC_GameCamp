#include "Source.h"
#include "MousePoint.h"
#include "Wall.h"

MousePoint::MousePoint()
{
	OldMouseInput = 0;
	NowMouseInput = 0;

	bmpX = 0;
	bmpY = 0;
	mpX = 0;
	mpY = 0;
	clickFlg = 0;
	killFlg = 0;
}

void MousePoint::GetMouseClick( const Wall *pwall )
{
	NowMouseInput = GetMouseInput();            //1フレーム前の状態をクリックした状態に更新

	//クリックしたとき
	if( clickFlg == 0 && ( ( ( OldMouseInput & MOUSE_INPUT_LEFT ) != MOUSE_INPUT_LEFT )       //１フレーム前は押されてないけど今は押されてる
		&& ( ( NowMouseInput & MOUSE_INPUT_LEFT ) == MOUSE_INPUT_LEFT ) ) )
	{
		GetMousePoint( &bmpX, &bmpY );                        //クリックしたときの座標を格納
		if( bmpX > ( pwall->x - pwall->mhitWidth / 2 ) && bmpY > ( pwall->y - pwall->mhitHeight / 2 ) )
		{
			if( bmpX < ( pwall->x + pwall->mhitWidth / 2 ) && bmpY < ( pwall->y + pwall->mhitHeight / 2 ) )
			{
				clickFlg = 1;
				DrawFormatString( 700, 100, 0x0000ff, "●" );
				if( bmpX > ( pwall->x - pwall->hitFenceX / 2 ) && bmpY > ( pwall->y - pwall->hitFenceY / 2 ) )
				{
					if( bmpX < ( pwall->x + pwall->hitFenceX / 2 ) && bmpY < ( pwall->y + pwall->hitFenceY / 2 ) )
					{
						clickFlg = 0;
						bmpX = 0;
						bmpY = 0;
						DrawFormatString( 700, 100, 0xff0000, "●" );
					}
				}
			}
			else
			{
				bmpX = 0;
				bmpY = 0;
			}
		}
		else
		{
			bmpX = 0;
			bmpY = 0;
		}
	}

	//ドラッグしてる時に
	if( clickFlg == 1 && ( ( ( OldMouseInput & MOUSE_INPUT_LEFT ) == MOUSE_INPUT_LEFT ) ) 
		&& ( ( NowMouseInput & MOUSE_INPUT_LEFT ) != MOUSE_INPUT_LEFT ) )
	{
	}

	//指を離した時
	if( clickFlg == 1 && ( ( ( OldMouseInput & MOUSE_INPUT_LEFT ) == MOUSE_INPUT_LEFT )
		&& ( ( NowMouseInput & MOUSE_INPUT_LEFT ) != MOUSE_INPUT_LEFT ) ) )
	{
		GetMousePoint( &mpX, &mpY );                        //クリックしたときの座標を格納
		clickFlg = 0;
		killFlg = TRUE;

		DrawFormatString( 700, 100, 0xff0000, "●" );

		if( mpX > ( pwall->x - pwall->hitFenceX / 2 ) && mpY > ( pwall->y - pwall->hitFenceY / 2 ) )
		{
			if( mpX < ( pwall->x + pwall->hitFenceX / 2 ) && mpY < ( pwall->y + pwall->hitFenceY / 2 ) )
			{
				DrawFormatString( 700, 100, 0xff0000, "●" );
				killFlg = FALSE;
			}
		}


		//if( mpX > ( pwall->x - pwall->mhitWidth / 2 ) && mpY > ( pwall->y - pwall->mhitHeight / 2 ) )
		//{
		//	if( mpX < ( pwall->x + pwall->mhitWidth / 2 ) && mpY < ( pwall->y + pwall->mhitHeight / 2 ) )
		//	{
		//		killFlg = TRUE;
		//		DrawFormatString( 700, 100, 0x0000ff, "●" );
		//		if( mpX > ( pwall->x - pwall->hitFenceX / 2 ) && mpY > ( pwall->y - pwall->hitFenceY / 2 ) )
		//		{
		//			if( mpX < ( pwall->x + pwall->hitFenceX / 2 ) && mpY < ( pwall->y + pwall->hitFenceY / 2 ) )
		//			{
		//				DrawFormatString( 700, 100, 0xff0000, "●" );
		//				killFlg = FALSE;
		//				clickFlg = 0;
		//			}
		//		}
		//	}
		//	else
		//	{
		//		clickFlg = 0;
		//		bmpX = 0;
		//		bmpY = 0;
		//		mpX = 0;
		//		mpY = 0;
		//	}
		//}
		//else
		//{
		//	clickFlg = 0;
		//	bmpX = 0;
		//	bmpY = 0;
		//	mpX = 0;
		//	mpY = 0;
		//}
	}

	OldMouseInput = NowMouseInput;

}

void MousePoint::PrintMouseClick()
{
	DrawFormatString( 700, 100, 0xffffff, "%d,%d,%d,%d", bmpX, bmpY, mpX, mpY );
}

bool MousePoint::CompCoor( int fC, int lC )
{
	if( fC > lC )
	{
		return true;
	}

	return false;
}

//int MousePoint::HitMouseClick( Wall *pwall )
//{
//
//}