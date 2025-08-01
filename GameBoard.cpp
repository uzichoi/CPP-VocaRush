// GameBoard.cpp

#include <cctype>
#include "GameBoard.h"
#include "InputController.h"
#include "WordView.h"

// 방향 이동값 정의: 오른쪽, 아래쪽, 대각선 ↘
const int GameBoard::dx[3] = { 1, 0, 1 };	// 선택한 방향에 따른 x축 이동량
const int GameBoard::dy[3] = { 0, 1, 1 };	// 선택한 방향에 따른 y축 이동량

GameBoard::GameBoard() {
	row = 10;
	col = 10;
}

GameBoardView& GameBoard::getBoardView() {
	return boardView;
}

void GameBoard::setSize(int row, int col) {
	// 입력값이 범위를 벗어나면 기본값(10*10)으로 조정
	if (row < 5 || row > 10) row = 10;	
	if (col < 5 || col > 10) col = 10;
	
	// 멤버 변수에 저장
	this->row = row;
	this->col = col;
	
	// 보드 크기만큼 grid 공간 생성. 나머지 셀에 무작위 알파벳 할당
	/*grid.resize(row, vector<char>(col));	// 2차원 배열 공간 생성
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			//char ch = rand() % 26 + 'a';	// 'a' ~ 'z'
			char ch = '*';
			grid[y][x] = ch;
		} 
	}*/

	// 보드 크기만큼 grid 공간 생성. 나머지 공간은 '*' 문자로 채움
	grid.resize(row, vector<char>(col, '*'));
	highlight.resize(row, vector<bool>(col, false));	
	boardView.setBoard(this);	// BoardView가 Board*에 접근 가능하게 함
}

bool GameBoard::canPlaceWord(Word word) {
	Direction direction = word.getDirection();

	int x = word.getX();      // 단어 시작 x 좌표
	int y = word.getY();      // 단어 시작 y 좌표
	string text = word.getText();  // 삽입할 단어

	for (int i = 0; i < text.size(); i++) {
		int wordX = x + dx[direction] * i;  // 단어의 i번째 글자가 들어갈 x 좌표
		int wordY = y + dy[direction] * i;  // 단어의 i번째 글자가 들어갈 y 좌표

		// 경계 체크
		if (wordY < 0 || wordY >= row || wordX < 0 || wordX >= col) 
			return false;	
	
		char current = grid[wordY][wordX];
		char needed = text[i];

		// if (current != needed)
		if (current != needed && current != '*')
			return false;	
	}

	return true;	// 배치 가능. 모든 조건 만족 시 성공
}

void GameBoard::placeWord(string text, int x, int y, Direction direction) {
	if (text[0] >= 'A' && text[0] <= 'Z')	// 첫 번째 문자가 대문자이면 소문자로 변환. words.txt 사용할 때만 필요한 구문
		text[0] = tolower(text[0]);

	for (int i = 0; i < text.size(); i++) {
		int wordX = x + dx[direction] * i;  // 단어의 i번째 글자가 들어갈 x 좌표
		int wordY = y + dy[direction] * i;  // 단어의 i번째 글자가 들어갈 y 좌표
		grid[wordY][wordX] = text[i];	// 실제 배치
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
	string correct = word.getText();	// 정답 단어

	int x = word.getX();
	int y = word.getY();
	Direction direction = word.getDirection();

	for (int i = 0; i < correct.size(); i++) {
		int wordX = x + dx[direction] * i;
		int wordY = y + dy[direction] * i;
		grid[wordY][wordX] = toupper(correct[i]);	// 대문자로 변환
		highlight[wordY][wordX] = true;	// 강조 표시
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
			grid[y][x] = '*';          // 기본 문자로 초기화
			highlight[y][x] = false;   // 강조 제거
		}
	}
}