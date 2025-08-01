#ifndef VIEW_H
#define VIEW_H

// 색상 정의
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <cstring>
#include "InputController.h"
#include "KeyCodes.h"
using namespace std;

class View {	// 추상 클래스
protected:
	int consoleWidth;	// 110
	int consoleHeight;	// 40
	int spacingBetweenLines = 3;	// 행간
	int spacingBetweenBoxes = 3; // 박스 사이 간격
public:
	View();
	virtual ~View();
	virtual void draw() = 0;	// 순수 가상 함수
	void gotoxy(int x, int y);
	void cls(int bgColor, int textColor);
	void textcolor(int fg_color, int bg_color);
	void drawBox(int x1, int y1, int x2, int y2);
	void drawBoxFill(int x1, int y1, int x2, int y2, int color);
	void getConsoleSize(int& width, int& height);
	void removeCursor();
};

#endif // !VIEW_H
