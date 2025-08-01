#include <iostream>
#include "InputController.h"
#include "KeyCodes.h"
#include <windows.h>
#include <conio.h>
using namespace std;

char InputController::getImmediateKeyInput() {	// ����� �Է�(���� 1��) �������� �Լ�
	while (true) {
		if (kbhit())
			return getch();		// �Է¹����� ��� �� ���� ����
	}
	
	return 0;				// �ƹ� �Է� ������ 0 ����
}

int InputController::getIntInput() {
	int num;
	cin >> num;
	return num;
}

string InputController::inputStringInput() {
	string text;
	getline(cin, text);
	return text;
}

void InputController::inputBoardSize(int& row, int& col) {
	cin >> row >> col;
	cin.ignore();
}

void InputController::waitForEscape() {		// ESC Ű �Է� ���
	while (true) {
		char key = getImmediateKeyInput();
		if (key == ESC) return;
	}

	Sleep(50);  // 50ms ���
}

bool InputController::waitForEnter() {		// Enter Ű �Է� ���
	while (true) {
		char key = getImmediateKeyInput();
		if (key == ENTER) return true;
	}

	Sleep(50);  // 50ms ���
}
