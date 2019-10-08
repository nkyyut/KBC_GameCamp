#include "Source.h"
#include "Source.h"

void DrawStage()
{
	DrawFormatString( 0, 0, 0xffffff, "SPACE TO TITLE" );

	if( opt.Kflg & PAD_INPUT_M )
	{
		GAMESTATE = GAME_TITLE;
	}
}