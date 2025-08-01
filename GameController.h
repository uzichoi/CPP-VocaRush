// GameController.h

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <Windows.h>
#include "KeyCodes.h"
#include "InputController.h"
#include "RankController.h"
#include "View.h"
#include "MenuView.h"
#include "ProgressView.h"
#include "GameBoardView.h"
#include "InputBoardView.h"
#include "Player.h"
#include "Word.h"
#include "GameBoard.h"
#include "WordController.h"

class GameController {
	Word word;
	WordController wordController;
	GameBoard gameBoard;
	Player player[2];
	InputController inputController;
	RankController rankController;	
	InputBoardView inputBoardView;
	ProgressView progressView;
	bool isGameOver;
	bool found;
	int currentPlayerIndex;
	int winnerIndex;
public:
	GameController();	// ������. ��ü ����
	~GameController();	// �Ҹ���
	void run();			// ��ü �帧 �Ѱ��ϴ� entry point
	bool startGame();	// ���� �� ȣ��
	void initializeGame();	// ���� ���� �ʱ�ȭ
	void configurateGame();	// �ʱ� ����
	void drawGameScreen();	// ���� ��ũ��(���� ȭ��) �׸���
	int assignTurn();	// �� ����
	void handleTurn();  // �� ����
	void determineWinner(bool allFound);	// ���� ����
	int getWinnerIndex();
	void endGame();     // ���� ó�� �� ��ŷ ����
};

#endif 
