#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <iostream>
#include <string>
using namespace std;

class InputController {
public:
	char getImmediateKeyInput(); // 실시간 키 입력 감지 (kbhit + getch), 입력 없으면 0 반환
	int getIntInput();	// 사용자로부터 정수를 입력받음
	string inputStringInput();
	void inputBoardSize(int& row, int& col);	// 보드 크기 입력
	void waitForEscape();		// ESC 입력 대기
	bool waitForEnter();		// Enter 입력 대기
};

#endif // !INPUTCONTROLLER_H
