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
	GameController();	// 생성자. 객체 생성
	~GameController();	// 소멸자
	void run();			// 전체 흐름 총괄하는 entry point
	bool startGame();	// 시작 뷰 호출
	void initializeGame();	// 게임 상태 초기화
	void configurateGame();	// 초기 세팅
	void drawGameScreen();	// 게임 스크린(메인 화면) 그리기
	int assignTurn();	// 턴 결정
	void handleTurn();  // 턴 관리
	void determineWinner(bool allFound);	// 승자 결정
	int getWinnerIndex();
	void endGame();     // 종료 처리 및 랭킹 저장
};

#endif 
