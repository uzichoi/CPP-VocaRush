#include "GameController.h"
#include "StartView.h"
#include "ConfigurationView.h"
#include "PlayerView.h"
#include "GameBoardView.h"
#include "GameSCreenView.h"
#include "ResultView.h"
#include "Windows.h"

GameController::GameController() {	// ������. ��� ���� �ʱ�ȭ
	isGameOver = false;
	found = false;
	currentPlayerIndex = 0;
	winnerIndex = -1;   // -1: ���� ���� ��, 0/1: �÷��̾� �ε��� 
};

GameController::~GameController() {}

void GameController::run() {
	while (true) {
		if (!startGame()) return;	// ���� ȭ�� �׸���
		
		initializeGame();		// ���� ���� �ʱ�ȭ
		configurateGame();		// ���� �ʱ� ���� (�÷��̾� �̸�, ���� ������)
		wordController.loadWordsFromFile("words.txt", 5);		// ���Ͽ��� �ܾ� 5�� �ҷ�����
		wordController.placeWordsOnBoard(gameBoard);		// �ܾ ���忡 ��ġ
		drawGameScreen();		// ���� ��ũ�� �׸���

		while (!isGameOver) {	// ���� ���� ������
			handleTurn();		// �� ����
		}

		endGame();		// ���� ȭ�� �׸���. ��ŷ ���
	}
}

bool GameController::startGame() {
	StartView startView;
	startView.draw();	

	while (true) {
		char key = inputController.getImmediateKeyInput();
			
		if (key == ENTER) {	// Press ENTER to start game
			return true;	// ���� ����
		}

		else if (key == TAB) {	// Press TAB to view menu
			MenuView menuView;	
			menuView.draw();		// �޴� ȭ�� ȣ��
			
			while (true) {
				char key = inputController.getImmediateKeyInput();
				if (key == ESC) break;
			}
			startView.draw();		// ���� ȭ�� ��ȣ��
		}

		else if (key == ESC) {	// Press ESC to Exit
			isGameOver = true;	// ���� ����
			return false;		// ���α׷� ����
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

void GameController::configurateGame() {	// ���� �ʱ� ����
	ConfigurationView configurationView;
	configurationView.draw();	// Configuration(�ʱ� ����-����) ȭ�� �׸���

	// ��Ʈ�ѷ��� ��ǥ �����ϴ�(�ϵ��ڵ���) �κ� ���� �ʿ�

	configurationView.gotoxy(65, 16);	// Player 1's name	
	player[0].setName(inputController.inputStringInput());

	configurationView.gotoxy(65, 19);	// Player 2's name
	player[1].setName(inputController.inputStringInput());

	configurationView.gotoxy(65, 22);	// Board Size
	int row = inputController.getIntInput();
	int col = inputController.getIntInput();
	gameBoard.setSize(row, col);

	configurationView.removeCursor();
	if (inputController.waitForEnter()) return;	// Enter Ű ������ �Լ� ����
}

void GameController::drawGameScreen() {
	GameScreenView gameScreenView;
	gameScreenView.draw();				// ���� ȭ�� Ʋ(���� + ���� ��� ��) �׸���
	gameBoard.getBoardView().draw();	// ������ �׸���
	player[0].getPlayerView()->draw(0, player[0]);	// �÷��̾� ����(�̸�, ����, �޺� ��) �׸���
	player[1].getPlayerView()->draw(1, player[1]);
	inputBoardView.draw();				// �Է�â �׸���
}

int GameController::assignTurn() {
	while (true) {
		char key = inputController.getImmediateKeyInput();

		if (key == 'a' || key == 'A') {
			if (player[0].getHP() > 0) return 0;
			else {
				cout << '\a';	// ���� �÷��̾ �Է� �õ��ϴ� ��� Beep
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
		else continue; // ��ȿ Ű �Է� �� ����
	}
}

void GameController::handleTurn() {
	int turn = assignTurn();	// �Էµ� Ű�� �� ����. �׻� 0 �Ǵ� 1 ��ȯ

	currentPlayerIndex = turn;
	Player& current = player[currentPlayerIndex];
	found = false;

	inputBoardView.gotoxy(54, 35);	
	string input = inputController.inputStringInput();

	// �ܾ� �˻� ���� ����
	for (int i = 0; i < wordController.getWordList().size(); i++) {
		Word& word = wordController.getWordList()[i];

		if (!word.isFound() && word.getText() == input) {	// ����
			word.markFoundWord(); 
			gameBoard.highlightWord(word);	// ���� �ܾ� ���̶�����
			found = true;
			current.addScore(100); // ���� +100
			current.addCombo();
			break;
		}
	}

	if (!found) {	// ����
		current.setCombo(0);
		current.subHP();
	}

	if (found) {	// ����
		gameBoard.getBoardView().draw();	// ���� ��ü �ٽ� �׸���
	}

	// �÷��̾� ���� ����. ����, �޺� ��
	player[currentPlayerIndex].getPlayerView()->draw(currentPlayerIndex, current);

	// ���� ������Ʈ �� �Է�â Ŭ����
	inputBoardView.clear();
	Sleep(300);

	// �ܾ ��� ã�Ҵ��� Ȯ��
	bool allFound = true;
	for (int i = 0; i < wordController.getWordList().size(); i++) {
		if (!wordController.getWordList()[i].isFound()) {
			allFound = false;
			break;
		}
	}

	// ���� ���� �����ؾ� ��

	// ��� �÷��̾� ��� �Ǵ� �ܾ� ��� �߰� �� ���� ���� 
	if ((player[0].getHP() <= 0 && player[1].getHP() <= 0) || allFound) {
		determineWinner(allFound);	// ���� ����
		isGameOver = true;
		return;
	}
}

void GameController::determineWinner(bool allFound) {
	if (allFound) {
		// ��� �ܾ ã�� ���: ������ ���� �÷��̾� �¸�
		winnerIndex = (player[0].getScore() >= player[1].getScore()) ? 0 : 1;
	}
	else if (player[0].getHP() <= 0 && player[1].getHP() <= 0) {
		// �� �� ���� ���: ������ ���� �÷��̾� �¸�
		winnerIndex = (player[0].getScore() >= player[1].getScore()) ? 0 : 1;
	}
	else if (player[0].getHP() <= 0) {
		// �÷��̾� 1�� ���� ���: �÷��̾� 2 �¸�
		winnerIndex = 1;
	}
	else if (player[1].getHP() <= 0) {
		// �÷��̾� 2�� ���� ���: �÷��̾� 1 �¸�
		winnerIndex = 0;
	}
}

void GameController::endGame() {
	int index = winnerIndex;
	string name = player[winnerIndex].getName();
	int score = player[winnerIndex].getScore();

	ResultView resultView;
	resultView.draw(index, name, score);	// ��� ȭ�� �׸���

	rankController.saveRank(score, name);	// ��ŷ ����
	rankController.displayRank("rank.txt");	// ���� ���
}

int GameController::getWinnerIndex() { return winnerIndex; }