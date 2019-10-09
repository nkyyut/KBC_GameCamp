#include "MousePoint.h"

MousePoint::MousePoint(){
	beforeMouseInput = 0;	//1フレーム前のマウスの状態（クリックされたかされてないか)を保存
	
}

int MousePoint::MousePointCheck() {
	
	if ((beforeMouseInput & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT	//前のマウスの状態が左クリックか確認して
			&& (GetMouseInput() & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) {	//今のマウスの状態が左クリックされているか確認
			MessageBox(NULL, "押された！", "マウス", MB_OK);
		}
		beforeMouseInput = GetMouseInput();
	}

