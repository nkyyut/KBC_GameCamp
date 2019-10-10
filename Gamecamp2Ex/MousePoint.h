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
		int i;

		void mpInit()
		{
			bmpX = 0;
			bmpY = 0;
			mpX = 0;
			mpY = 0;
			dmpX = 0;
			dmpY = 0;
			clickFlg = 0;
			wallFlg = 0;
			i = 0;
		}

	private :
		int OldMouseInput;
		int NowMouseInput;
};