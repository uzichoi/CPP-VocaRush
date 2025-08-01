// Word.h
// 단어 그 자체의 정보와 상태(위치, 발견 여부 등)을 관리하는 클래스
// words.txt에서 단어를 불러오고, 보드 위에 단어를 무작위로 배치하는 역할

#ifndef WORD_H
#define WORD_H

#include <string>
#include "Direction.h"
#include "WordView.h"
using namespace std;

class Word {
	string text;
	int startX, startY;
	Direction direction;
	WordView wordView;
	bool found;
public:
	Word(string text = "");
	WordView& getWordView();
	void setPosition(int x, int y, Direction direction);
	const string& getText();
	int getX();
	int getY();
	Direction getDirection();
	bool isFound();
	void markFoundWord();
};

#endif // !WORD_H
