#include "Drawtitle.h"

struct OPERATE opt;
void DrawTitle()
{

	SetFontSize( _FONTSIZE_S );

	DrawFormatString( 0, 0, 0xffffff, "SPACE TO MAIN" );

	if( opt.Kflg & PAD_INPUT_M )
	{
		GAMESTATE = GAME_INIT;
	}

}