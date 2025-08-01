#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <iostream>
#include <string>
using namespace std;

class InputController {
public:
	char getImmediateKeyInput(); // �ǽð� Ű �Է� ���� (kbhit + getch), �Է� ������ 0 ��ȯ
	int getIntInput();	// ����ڷκ��� ������ �Է¹���
	string inputStringInput();
	void inputBoardSize(int& row, int& col);	// ���� ũ�� �Է�
	void waitForEscape();		// ESC �Է� ���
	bool waitForEnter();		// Enter �Է� ���
};

#endif // !INPUTCONTROLLER_H
