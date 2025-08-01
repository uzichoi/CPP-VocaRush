#include "StartView.h"

void StartView::draw() {
    cls(15, 0);

    // 제목 중앙 정렬
    string welcomeMsg = "Welcome to Voca Rush!";

    int welcomeX = (consoleWidth - welcomeMsg.length()) / 2;
    gotoxy(welcomeX, 10);
    cout << welcomeMsg << endl;

    string vocaRush[] = {  // 타이틀 문자열 "VOCA RUSH" 
        "____    ____   ______     ______      ___      ",
        "\\   \\  /   /  /  __  \\   /      |    /   \\     ",
        " \\   \\/   /  |  |  |  | |  ,----'   /  ^  \\    ",
        "  \\      /   |  |  |  | |  |       /  /_\\  \\   ",
        "   \\    /    |  `--'  | |  `----. /  _____  \\  ",
        "    \\__/      \\______/   \\______|/__/     \\__\\ ",
        ".______       __    __       _______. __    __  ",
        "|   _  \\     |  |  |  |     /       ||  |  |  | ",
        "|  |_)  |    |  |  |  |    |   (----`|  |__|  | ",
        "|      /     |  |  |  |     \\   \\    |   __   | ",
        "|  |\\  \\----.|  `--'  | .----)   |   |  |  |  | ",
        "| _| `._____| \\______/  |_______/    |__|  |__| "
    };

    // ASCII 아트 중앙 정렬 (가장 긴 줄 기준)
    int maxLineLength = vocaRush[0].length(); // 첫 번째 줄 길이
    int artX = (consoleWidth - maxLineLength) / 2;  // 30
    
    textcolor(CYAN1, WHITE);
    // 타이틀 출력
    for (int i = 0; i < 12; i++) {
        gotoxy(artX, 12 + i);
        cout << vocaRush[i] << endl;
    }

    textcolor(BLACK, WHITE);

    // 하단 메뉴 대칭 배치
    string leftMenu = "Press ENTER to start game";
    string rightMenu = "Press TAB to view menu";

    int leftX = consoleWidth / 4 - leftMenu.length() / 2;
    int rightX = consoleWidth * 3 / 4 - rightMenu.length() / 2;

    gotoxy(leftX, 28);
    //textcolor(1, 700000);
    cout << leftMenu;

    gotoxy(rightX, 28);
    //textcolor(3, 7);
    cout << rightMenu;
}
