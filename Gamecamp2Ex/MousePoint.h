#pragma once

#include "Wall.h"

class MousePoint
{
	public :
		MousePoint();
		void GetMouseClick( const Wall *pwall );
		void PrintMouseClick();
		//int HitMouseClick( Wall *pwall );
		bool killFlg;
		int bmpX;
		int bmpY;
		int mpX;
		int mpY;
		int dmpX;
		int dmpY;
		int clickFlg;

	private :
		int OldMouseInput;
		int NowMouseInput;
};