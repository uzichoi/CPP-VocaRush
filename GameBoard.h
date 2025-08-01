// GameBoard.h
// ������ ���¸� �����ϴ� Ŭ���� 

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
	vector<vector<char>> grid;		// ���� ���� ���� ������ ��� ����
	vector<vector<bool>> highlight;	 
	GameBoardView boardView;	
	static const int dx[];
	static const int dy[];
	int row, col;
public:
	GameBoard();
	GameBoardView& getBoardView();
	void setSize(int row, int col);	// ���� ������ ����
	bool canPlaceWord(Word word);	// �ܾ� ��ġ ���� ���� �Ǵ�
	void placeWord(string text, int x, int y, Direction direction);	// �ܾ� ��ġ
	void printBoard();	// ���� ���
	void highlightWord(Word word);	// ���� �ܾ� ���̶�����
	bool isHighlighted(int x, int y);
	int getRow();
	int getCol();
	char getCharAt(int y, int x);
	void clear();
};

#endif // !GAMEBOARD_H
