// GameBoardView.h

#ifndef GAMEBOARDVIEW_H
#define GAMEBOARDVIEW_H

#include "View.h"

class GameBoard;	// 전방 선언으로 순환 참조 방지

class GameBoardView : public View {
protected:
	GameBoard* board;	// 상위 보드 참조
public:
	GameBoardView();
	~GameBoardView();
	void draw();
	void setBoard(GameBoard* board);
};

#endif // !GAMEBOARDVIEW_H
