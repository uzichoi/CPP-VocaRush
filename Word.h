// Word.h
// �ܾ� �� ��ü�� ������ ����(��ġ, �߰� ���� ��)�� �����ϴ� Ŭ����
// words.txt���� �ܾ �ҷ�����, ���� ���� �ܾ �������� ��ġ�ϴ� ����

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
