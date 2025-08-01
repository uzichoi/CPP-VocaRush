#include "GameController.h"
#include "StartView.h"
#include "ConfigurationView.h"
#include "PlayerView.h"
#include "GameBoardView.h"
#include "GameSCreenView.h"
#include "ResultView.h"
#include "Windows.h"

GameController::GameController() {	// 생성자. 멤버 변수 초기화
	isGameOver = false;
	found = false;
	currentPlayerIndex = 0;
	winnerIndex = -1;   // -1: 게임 진행 중, 0/1: 플레이어 인덱스 
};

GameController::~GameController() {}

void GameController::run() {
	while (true) {
		if (!startGame()) return;	// 시작 화면 그리기
		
		initializeGame();		// 게임 상태 초기화
		configurateGame();		// 게임 초기 설정 (플레이어 이름, 보드 사이즈)
		wordController.loadWordsFromFile("words.txt", 5);		// 파일에서 단어 5개 불러오기
		wordController.placeWordsOnBoard(gameBoard);		// 단어를 보드에 배치
		drawGameScreen();		// 게임 스크린 그리기

		while (!isGameOver) {	// 게임 오버 전까지
			handleTurn();		// 턴 관리
		}

		endGame();		// 종료 화면 그리기. 랭킹 기록
	}
}

bool GameController::startGame() {
	StartView startView;
	startView.draw();	

	while (true) {
		char key = inputController.getImmediateKeyInput();
			
		if (key == ENTER) {	// Press ENTER to start game
			return true;	// 게임 시작
		}

		else if (key == TAB) {	// Press TAB to view menu
			MenuView menuView;	
			menuView.draw();		// 메뉴 화면 호출
			
			while (true) {
				char key = inputController.getImmediateKeyInput();
				if (key == ESC) break;
			}
			startView.draw();		// 시작 화면 재호출
		}

		else if (key == ESC) {	// Press ESC to Exit
			isGameOver = true;	// 게임 오버
			return false;		// 프로그램 종료
		}

		Sleep(60);
	}
}

void GameController::initializeGame() {
	isGameOver = false;
	winnerIndex = -1;
	currentPlayerIndex = 0;
	found = false;
	player[0].setScore(0);
	player[0].setHP(3);
	player[0].setCombo(0);
	player[0].setMaxCombo(0);
	player[1].setScore(0);
	player[1].setHP(3);
	player[1].setCombo(0);
	player[1].setMaxCombo(0);
	wordController.resetWordList();
	gameBoard.clear();
}

void GameController::configurateGame() {	// 게임 초기 설정
	ConfigurationView configurationView;
	configurationView.draw();	// Configuration(초기 구성-설정) 화면 그리기

	// 컨트롤러가 좌표 지정하는(하드코딩된) 부분 수정 필요

	configurationView.gotoxy(65, 16);	// Player 1's name	
	player[0].setName(inputController.inputStringInput());

	configurationView.gotoxy(65, 19);	// Player 2's name
	player[1].setName(inputController.inputStringInput());

	configurationView.gotoxy(65, 22);	// Board Size
	int row = inputController.getIntInput();
	int col = inputController.getIntInput();
	gameBoard.setSize(row, col);

	configurationView.removeCursor();
	if (inputController.waitForEnter()) return;	// Enter 키 눌리면 함수 종료
}

void GameController::drawGameScreen() {
	GameScreenView gameScreenView;
	gameScreenView.draw();				// 메인 화면 틀(보드 + 영역 배경 등) 그리기
	gameBoard.getBoardView().draw();	// 보드판 그리기
	player[0].getPlayerView()->draw(0, player[0]);	// 플레이어 정보(이름, 점수, 콤보 등) 그리기
	player[1].getPlayerView()->draw(1, player[1]);
	inputBoardView.draw();				// 입력창 그리기
}

int GameController::assignTurn() {
	while (true) {
		char key = inputController.getImmediateKeyInput();

		if (key == 'a' || key == 'A') {
			if (player[0].getHP() > 0) return 0;
			else {
				cout << '\a';	// 죽은 플레이어가 입력 시도하는 경우 Beep
				continue;	
			}
		}
		if (key == 'l' || key == 'L') {
			if (player[1].getHP() > 0) return 1;
			else {
				cout << '\a';
				continue;
			}
		}
		else continue; // 무효 키 입력 시 무시
	}
}

void GameController::handleTurn() {
	int turn = assignTurn();	// 입력된 키로 턴 결정. 항상 0 또는 1 반환

	currentPlayerIndex = turn;
	Player& current = player[currentPlayerIndex];
	found = false;

	inputBoardView.gotoxy(54, 35);	
	string input = inputController.inputStringInput();

	// 단어 검색 먼저 수행
	for (int i = 0; i < wordController.getWordList().size(); i++) {
		Word& word = wordController.getWordList()[i];

		if (!word.isFound() && word.getText() == input) {	// 정답
			word.markFoundWord(); 
			gameBoard.highlightWord(word);	// 정답 단어 하이라이팅
			found = true;
			current.addScore(100); // 점수 +100
			current.addCombo();
			break;
		}
	}

	if (!found) {	// 오답
		current.setCombo(0);
		current.subHP();
	}

	if (found) {	// 정답
		gameBoard.getBoardView().draw();	// 보드 전체 다시 그리기
	}

	// 플레이어 정보 갱신. 점수, 콤보 등
	player[currentPlayerIndex].getPlayerView()->draw(currentPlayerIndex, current);

	// 상태 업데이트 후 입력창 클리어
	inputBoardView.clear();
	Sleep(300);

	// 단어를 모두 찾았는지 확인
	bool allFound = true;
	for (int i = 0; i < wordController.getWordList().size(); i++) {
		if (!wordController.getWordList()[i].isFound()) {
			allFound = false;
			break;
		}
	}

	// 종료 조건 검토해야 함

	// 모든 플레이어 사망 또는 단어 모두 발견 시 게임 종료 
	if ((player[0].getHP() <= 0 && player[1].getHP() <= 0) || allFound) {
		determineWinner(allFound);	// 승자 결정
		isGameOver = true;
		return;
	}
}

void GameController::determineWinner(bool allFound) {
	if (allFound) {
		// 모든 단어를 찾은 경우: 점수가 높은 플레이어 승리
		winnerIndex = (player[0].getScore() >= player[1].getScore()) ? 0 : 1;
	}
	else if (player[0].getHP() <= 0 && player[1].getHP() <= 0) {
		// 둘 다 죽은 경우: 점수가 높은 플레이어 승리
		winnerIndex = (player[0].getScore() >= player[1].getScore()) ? 0 : 1;
	}
	else if (player[0].getHP() <= 0) {
		// 플레이어 1만 죽은 경우: 플레이어 2 승리
		winnerIndex = 1;
	}
	else if (player[1].getHP() <= 0) {
		// 플레이어 2만 죽은 경우: 플레이어 1 승리
		winnerIndex = 0;
	}
}

void GameController::endGame() {
	int index = winnerIndex;
	string name = player[winnerIndex].getName();
	int score = player[winnerIndex].getScore();

	ResultView resultView;
	resultView.draw(index, name, score);	// 결과 화면 그리기

	rankController.saveRank(score, name);	// 랭킹 저장
	rankController.displayRank("rank.txt");	// 파일 출력
}

int GameController::getWinnerIndex() { return winnerIndex; }