#include "MousePoint.h"

MousePoint::MousePoint(){
	beforeMouseInput = 0;	//1�t���[���O�̃}�E�X�̏�ԁi�N���b�N���ꂽ������ĂȂ���)��ۑ�
	
}

int MousePoint::MousePointCheck() {
	
	if ((beforeMouseInput & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT	//�O�̃}�E�X�̏�Ԃ����N���b�N���m�F����
			&& (GetMouseInput() & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) {	//���̃}�E�X�̏�Ԃ����N���b�N����Ă��邩�m�F
			MessageBox(NULL, "�����ꂽ�I", "�}�E�X", MB_OK);
		}
		beforeMouseInput = GetMouseInput();
	}

