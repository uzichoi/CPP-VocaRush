// InputBoardView.cpp

#include "InputBoardView.h"

void InputBoardView::draw() {
	int boxX = 30;	// 30
	int boxY = 33;
	int boxWidth = 50;
	int boxHeight = 5;

	textcolor(BLACK, WHITE);
	drawBox(boxX, boxY, boxX + boxWidth - 1, boxY + boxHeight - 1);
	
	gotoxy(boxX + 3, boxY + boxHeight / 2);  // (32, 35)
	cout << "Input >> ";
}

void InputBoardView::clear() {
	textcolor(WHITE, WHITE);
	gotoxy(54, 35);
	cout << "                    ";	// �������� �����
	gotoxy(54, 35);
	textcolor(BLACK, WHITE);
	cout << "";	// Ŀ���� �����̵���
}