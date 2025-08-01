#include <iostream>
#include "InputController.h"
#include "KeyCodes.h"
#include <windows.h>
#include <conio.h>
using namespace std;

char InputController::getImmediateKeyInput() {	// 사용자 입력(문자 1개) 가져오는 함수
	while (true) {
		if (kbhit())
			return getch();		// 입력받으면 즉시 그 문자 리턴
	}
	
	return 0;				// 아무 입력 없으면 0 리턴
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

void InputController::waitForEscape() {		// ESC 키 입력 대기
	while (true) {
		char key = getImmediateKeyInput();
		if (key == ESC) return;
	}

	Sleep(50);  // 50ms 대기
}

bool InputController::waitForEnter() {		// Enter 키 입력 대기
	while (true) {
		char key = getImmediateKeyInput();
		if (key == ENTER) return true;
	}

	Sleep(50);  // 50ms 대기
}
