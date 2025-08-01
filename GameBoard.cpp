// GameBoard.cpp

#include <cctype>
#include "GameBoard.h"
#include "InputController.h"
#include "WordView.h"

// ���� �̵��� ����: ������, �Ʒ���, �밢�� ��
const int GameBoard::dx[3] = { 1, 0, 1 };	// ������ ���⿡ ���� x�� �̵���
const int GameBoard::dy[3] = { 0, 1, 1 };	// ������ ���⿡ ���� y�� �̵���

GameBoard::GameBoard() {
	row = 10;
	col = 10;
}

GameBoardView& GameBoard::getBoardView() {
	return boardView;
}

void GameBoard::setSize(int row, int col) {
	// �Է°��� ������ ����� �⺻��(10*10)���� ����
	if (row < 5 || row > 10) row = 10;	
	if (col < 5 || col > 10) col = 10;
	
	// ��� ������ ����
	this->row = row;
	this->col = col;
	
	// ���� ũ�⸸ŭ grid ���� ����. ������ ���� ������ ���ĺ� �Ҵ�
	/*grid.resize(row, vector<char>(col));	// 2���� �迭 ���� ����
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			//char ch = rand() % 26 + 'a';	// 'a' ~ 'z'
			char ch = '*';
			grid[y][x] = ch;
		} 
	}*/

	// ���� ũ�⸸ŭ grid ���� ����. ������ ������ '*' ���ڷ� ä��
	grid.resize(row, vector<char>(col, '*'));
	highlight.resize(row, vector<bool>(col, false));	
	boardView.setBoard(this);	// BoardView�� Board*�� ���� �����ϰ� ��
}

bool GameBoard::canPlaceWord(Word word) {
	Direction direction = word.getDirection();

	int x = word.getX();      // �ܾ� ���� x ��ǥ
	int y = word.getY();      // �ܾ� ���� y ��ǥ
	string text = word.getText();  // ������ �ܾ�

	for (int i = 0; i < text.size(); i++) {
		int wordX = x + dx[direction] * i;  // �ܾ��� i��° ���ڰ� �� x ��ǥ
		int wordY = y + dy[direction] * i;  // �ܾ��� i��° ���ڰ� �� y ��ǥ

		// ��� üũ
		if (wordY < 0 || wordY >= row || wordX < 0 || wordX >= col) 
			return false;	
	
		char current = grid[wordY][wordX];
		char needed = text[i];

		// if (current != needed)
		if (current != needed && current != '*')
			return false;	
	}

	return true;	// ��ġ ����. ��� ���� ���� �� ����
}

void GameBoard::placeWord(string text, int x, int y, Direction direction) {
	if (text[0] >= 'A' && text[0] <= 'Z')	// ù ��° ���ڰ� �빮���̸� �ҹ��ڷ� ��ȯ. words.txt ����� ���� �ʿ��� ����
		text[0] = tolower(text[0]);

	for (int i = 0; i < text.size(); i++) {
		int wordX = x + dx[direction] * i;  // �ܾ��� i��° ���ڰ� �� x ��ǥ
		int wordY = y + dy[direction] * i;  // �ܾ��� i��° ���ڰ� �� y ��ǥ
		grid[wordY][wordX] = text[i];	// ���� ��ġ
	}
}

void GameBoard::printBoard() {
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			cout << grid[y][x] << ' ';
		}
		cout << endl;
	}
}

void GameBoard::highlightWord(Word word) {
	string correct = word.getText();	// ���� �ܾ�

	int x = word.getX();
	int y = word.getY();
	Direction direction = word.getDirection();

	for (int i = 0; i < correct.size(); i++) {
		int wordX = x + dx[direction] * i;
		int wordY = y + dy[direction] * i;
		grid[wordY][wordX] = toupper(correct[i]);	// �빮�ڷ� ��ȯ
		highlight[wordY][wordX] = true;	// ���� ǥ��
	}
}

bool GameBoard::isHighlighted(int y, int x) {
	return highlight[y][x];
}

int GameBoard::getRow() {
	return row;
}

int GameBoard::getCol() {
	return col;
}

char GameBoard::getCharAt(int y, int x) {
	return grid[y][x];
}

void GameBoard::clear() {
	if (grid.empty() || highlight.empty())
		return; 

	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			grid[y][x] = '*';          // �⺻ ���ڷ� �ʱ�ȭ
			highlight[y][x] = false;   // ���� ����
		}
	}
}