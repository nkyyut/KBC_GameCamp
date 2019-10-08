#pragma once

class MousePoint
{
	public :
		MousePoint();
		void GetMouseClick();
		void PrintMouseClick();
		bool killFlg = 0;
		int bmpX, bmpY;
		int mpX, mpY;

	private :
		int OldMouseInput;
		int NowMouseInput;
};