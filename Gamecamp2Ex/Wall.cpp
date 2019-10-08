#include "Source.h"
#include "Wall.h"
#include "MousePoint.h"

//コンストラクタ
Wall::Wall()
{
	x = 700 / 2;
	y = -10;
	moveSpeed = 5;

	mhitWidth = 250;
	mhitHeight = 200;

	hitFenceX = 200;
	hitFenceY = 20;
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

void Wall::BreakWall( const MousePoint mPoint )
{
	if( mPoint.killFlg == TRUE )
	{
		if( mPoint.bmpX > ( x - mhitWidth / 2 ) && mPoint.bmpY > ( y - mhitHeight / 2 ) )
		{
			if( mPoint.mpX < ( x + mhitWidth / 2 ) && mPoint.mpY < ( y + mhitHeight / 2 ) )
			{

				if( mPoint.mpX > ( x - mhitWidth / 2 ) && mPoint.mpY > ( y - mhitHeight / 2 ) )
				{
					DrawFormatString( 900, 100, 0x000000, "クリック範囲内" );
				}

			}
		}
	}
}