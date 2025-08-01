// ResultView.cpp

#include <string>
#include "ResultView.h"
#include "Windows.h"
#include "InputController.h"

void ResultView::draw() {}

void ResultView::draw(int index, string name, int score) {
	cls(WHITE, BLACK);

    string gameOverMsg[] = {
        "  _______      ___     .___  ___.  _______ ",
        " /  _____|    /   \\    |   \\/   | |   ____|",
        "|  |  __     /  ^  \\   |  \\  /  | |  |__   ",
        "|  | |_ |   /  /_\\  \\  |  |\\/|  | |   __|  ",
        "|  |__| |  /  _____  \\ |  |  |  | |  |____ ",
        " \\______| /__/     \\__ |__|  |__| |_______|",
        "  ______   ____    ____  _______ .______     ",
        " /  __  \\  \\   \\  /   / |   ____||   _  \\   ",
        "|  |  |  |  \\   \\/   /  |  |__   |  |_)  |   ",
        "|  |  |  |   \\      /   |   __|  |      /    ",
        "|  `--'  |    \\    /    |  |____ |  |\\  \\----.",
        " \\______/      \\__/     |_______|| _| `._____| "
    };

	int maxLineLength = gameOverMsg[0].length();
    int artX = (consoleWidth - maxLineLength) / 2;

    textcolor(RED1, WHITE);
    for (int i = 0; i < 12; i++) {
        gotoxy(artX, 10 + i);
        cout << gameOverMsg[i] << endl;
    }

    string winnerMsg = "Winner is Player " + to_string(index + 1) + " : " + name + " (" + to_string(score) + ")";

    int winnerX = (consoleWidth - winnerMsg.length()) / 2;
    gotoxy(winnerX, 26);
    textcolor(BLACK, WHITE);
    cout << winnerMsg;

    string retryMsg = "Press ENTER to restart game";
    int retryX = (consoleWidth - retryMsg.length()) / 2;
    gotoxy(retryX, 35);
    textcolor(BLUE1, WHITE);
    cout << retryMsg;

    InputController input;
    if(input.waitForEnter())    // 엔터 입력 대기
        return;
}