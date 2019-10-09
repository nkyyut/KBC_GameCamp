#include "Source.h"
#include "Wall.h"
#include "MousePoint.h"

//コンストラクタ
Wall::Wall()
{
	x = 700 / 2;
	y = -10;
	moveSpeed = 5;

	mhitWidth = 700;
	mhitHeight = 200;

	hitFenceX = 700;
	hitFenceY = 60;
}

Wall::~Wall()
{
	x = 0;
	y = 0;
	moveSpeed = 0;
}

void Wall::MoveWall()
{
	y += moveSpeed;
}

int Wall::ScreenOut()
{

	if( y >= 768 )
	{
		return 1;
	}

	return 0;
}

void Wall::WallDraw()
{
	DrawBox( x - ( hitFenceX / 2 ), y - ( hitFenceY / 2 ), x + ( hitFenceX / 2 ), y + ( hitFenceY / 2 ), 0xffffff, TRUE );
}

void Wall::HitmouseRange()
{
	int mX = 0;
	int mY = 0;
	int Mouse;
	Mouse = GetMouseInput();

	//当たり判定場所の描画
	DrawBox( x - mhitWidth / 2, y - mhitHeight / 2, x + mhitWidth / 2, y + mhitHeight / 2, 0xF8A900, TRUE );

	GetMousePoint( &mX, &mY );	//マウス座標取得
	if( Mouse & MOUSE_INPUT_LEFT ) {
		if( mX > ( x - mhitWidth / 2 ) && mY > ( y - mhitHeight / 2 ) )
		{
			if( mX < ( x + mhitWidth / 2 ) && mY < ( y + mhitHeight / 2 ) )
			{
				DrawFormatString( 900, 100, 0x000000, "クリック範囲内" );
				static int Flash = 0;
				static int Flash2 = 0;

				if( Flash++ > 10 )
				{
					Flash2 = 1;
					Flash = 0;
				}

			}
		}
	}
}

bool Wall::LineAndLine( int A1x, int A1y, int A2x, int A2y, int B1x, int B1y, int B2x, int B2y )
{
	{
		const int baseX = B2x - B1x;
		const int baseY = B2y - B1y;
		const int sub1X = A1x - B1x;
		const int sub1Y = A1y - B1y;
		const int sub2X = A2x - B1x;
		const int sub2Y = A2y - B1y;

		const int bs1 = baseX * sub1Y - baseY * sub1X;
		const int bs2 = baseX * sub2Y - baseY * sub2X;
		const int re = bs1 * bs2;

		if( re > 0 )
		{
			return false;
		}
	}

	{
		const int baseX = A2x - A1x;
		const int baseY = A2y - A1y;
		const int sub1X = B1x - A1x;
		const int sub1Y = B1y - A1y;
		const int sub2X = B2x - A1x;
		const int sub2Y = B2y - A1y;

		const int bs1 = baseX * sub1Y - baseY * sub1Y;
		const int bs2 = baseX * sub2Y - baseY * sub2X;
		const int re = bs1 * bs2;

		if( re > 0 )
		{
			return false;
		}
	}

	return true;
}

bool Wall::RectAndLine( int right, int left, int top, int bottom, int x1, int y1, int x2, int y2 )
{
	if( LineAndLine( left, top, right, top, x1, y1, x2, y2 ) )
	{
		return true;
	}
	if( LineAndLine( right, top, right, bottom, x1, y1, x2, y2 ) )
	{
		return true;
	}
	if( LineAndLine( right, bottom, left, bottom, x1, y1, x2, y2 ) )
	{
		return true;
	}
	if( LineAndLine( left, bottom, left, top, x1, y1, x2, y2 ) )
	{
		return true;
	}
	return false;
}

//int Wall::BreakWall( MousePoint mPoint )
//{
//
//	if( mPoint.bmpX > ( x - mhitWidth / 2 ) && mPoint.bmpY > ( y - mhitHeight / 2 ) )
//	{
//		if( mPoint.bmpX < ( x + mhitWidth / 2 ) && mPoint.bmpY < ( y + mhitHeight / 2 ) )
//		{
//			if( mPoint.mpX > ( x - mhitWidth / 2 ) && mPoint.mpY > ( y - mhitHeight / 2 ) )
//			{
//				if( mPoint.mpX < ( x + mhitWidth / 2 ) && mPoint.mpY < ( y + mhitHeight / 2 ) )
//				{
//
//				}
//			}
//			if( mPoint.mpX > ( x - hitFenceX / 2 ) && mPoint.mpY > ( y - hitFenceY / 2 ) )
//			{
//				if( mPoint.mpX < ( x + hitFenceX / 2 ) && mPoint.mpY < ( y + hitFenceY / 2 ) )
//				{
//					return 1;
//				}
//			}
//
//		}
//	}
//
//	return 0;
//
//}