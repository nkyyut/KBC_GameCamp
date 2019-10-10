#pragma once

#include "Wall.h"

class MousePoint
{
	public :
		MousePoint();
		void GetMouseClick( const Wall *pwall );
		void PrintMouseClick();
		bool CompCoor( int fC, int lC );
		//int HitMouseClick( Wall *pwall );
		bool killFlg;
		int bmpX;
		int bmpY;
		int mpX;
		int mpY;
		int dmpX;
		int dmpY;
		int clickFlg;
		int wallFlg;

	private :
		int OldMouseInput;
		int NowMouseInput;
};