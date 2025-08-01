// GameBoard.h
// 보드의 상태를 저장하는 클래스 

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include "GameBoardView.h"
#include "Direction.h"
#include "Word.h"
using namespace std;

class GameBoard {
	vector<vector<char>> grid;		// 문자 셀을 가진 보드판 멤버 변수
	vector<vector<bool>> highlight;	 
	GameBoardView boardView;	
	static const int dx[];
	static const int dy[];
	int row, col;
public:
	GameBoard();
	GameBoardView& getBoardView();
	void setSize(int row, int col);	// 보드 사이즈 설정
	bool canPlaceWord(Word word);	// 단어 배치 가능 여부 판단
	void placeWord(string text, int x, int y, Direction direction);	// 단어 배치
	void printBoard();	// 보드 출력
	void highlightWord(Word word);	// 정답 단어 하이라이팅
	bool isHighlighted(int x, int y);
	int getRow();
	int getCol();
	char getCharAt(int y, int x);
	void clear();
};

#endif // !GAMEBOARD_H
