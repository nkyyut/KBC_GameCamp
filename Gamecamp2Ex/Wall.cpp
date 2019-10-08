#include "Source.h"
#include "Wall.h"

//コンストラクタ
Wall::Wall()
{
	x = 700 / 2;
	y = -10;
	moveSpeed = 4;

	mhitWidth = 200;
	mhitHeight = 100;
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
	DrawBox( x - 100, y - 10, x + 100, y + 10, 0xffffff, TRUE );
}

void Wall::HitmouseRange()
{
	DrawBox( x - mhitWidth / 2, y - mhitHeight / 2, x + mhitWidth / 2, y + mhitHeight / 2, 0xF8A900, TRUE );
}