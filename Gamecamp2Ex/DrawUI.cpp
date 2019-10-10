#include "Source.h"
#include "DrawUI.h"

void DrawUI( int nowTime )
{
	int visualTime = 0;
	static int Time = 2400;

	//DrawBox( 700, 0, 1024, 768, 0xffffff, TRUE );

	//DrawRotaGraph( ( _SCREENSIZE_X / 4 ) * 3, ( _SCREENSIZE_Y / 2 ), 1.0f, 0, pic->Gage, TRUE );

	visualTime = ( Time - nowTime ) / 60;

	SetFontSize( _FONTSIZE_L );
	DrawFormatString( ( 1024 / 2 ) - 100, 0, 0xff0000, "ŽžŠÔ : %d", visualTime );

}