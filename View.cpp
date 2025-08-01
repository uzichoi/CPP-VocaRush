#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <Windows.h>
#include <cstdio>
#include "View.h"

View::View() {
	int consoleWidth, consoleHeight;
	getConsoleSize(consoleWidth, consoleHeight);
	this->consoleWidth = consoleWidth;
	this->consoleHeight = consoleHeight;
}

View::~View() {}

void View::gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void View::cls(int bgColor, int textColor) {
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bgColor, textColor);
	system(cmd);
}

void View::textcolor(int fg_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void View::drawBox(int x1, int y1, int x2, int y2) {
	int x, y;
	//int len = strlen(ch);
	for (x = x1; x <= x2; x += 2) { // 한글은 2칸씩 차지
		gotoxy(x, y1);
		printf("%s", "─"); // ㅂ 누르고 한자키 누르고 선택
		gotoxy(x, y2);
		printf("%s", "─");
	}
	for (y = y1; y <= y2; y++) {
		gotoxy(x1, y);
		printf("%s", "│");
		gotoxy(x2, y);
		printf("%s", "│");
	}
	gotoxy(x1, y1); printf("┌");
	gotoxy(x1, y2); printf("└");
	gotoxy(x2, y1); printf("┐");
	gotoxy(x2, y2); printf("┘");
}

void View::drawBoxFill(int x1, int y1, int x2, int y2, int color) { 
	// (x1, y1): 좌상단 좌표
	// (x2, y2): 우하단 좌표
	int x, y;

	textcolor(BLACK, WHITE);
	for (x = x1; x <= x2; x += 2) { // 한글은 2칸씩 차지한다.
		gotoxy(x, y1);
		printf("%s", "─"); // ㅂ 누르고 한자키 누르고 선택
		gotoxy(x, y2);
		printf("%s", "─");
	}
	for (y = y1; y <= y2; y++) {
		gotoxy(x1, y);
		printf("%s", "│");
		gotoxy(x2, y);
		printf("%s", "│");
	}
	gotoxy(x1, y1); printf("┌");
	gotoxy(x1, y2); printf("└");
	gotoxy(x2, y1); printf("┐");
	gotoxy(x2, y2); printf("┘");
	//getch();

	for (y = y1 + 1; y < y2; y++) {
		for (x = x1 + 2; x < x2; x++) {
			textcolor(color, color);
			gotoxy(x, y);
			printf(" ");
		}
	}
}

void View::getConsoleSize(int& width, int& height) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void View::removeCursor() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}