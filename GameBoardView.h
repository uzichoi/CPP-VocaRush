// GameBoardView.h

#ifndef GAMEBOARDVIEW_H
#define GAMEBOARDVIEW_H

#include "View.h"

class GameBoard;	// ���� �������� ��ȯ ���� ����

class GameBoardView : public View {
protected:
	GameBoard* board;	// ���� ���� ����
public:
	GameBoardView();
	~GameBoardView();
	void draw();
	void setBoard(GameBoard* board);
};

#endif // !GAMEBOARDVIEW_H
