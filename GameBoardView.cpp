// BoardView.cpp

#include "GameBoardView.h"
#include "GameBoard.h"

GameBoardView::GameBoardView() { board = nullptr; } // ����� �ʱ�ȭ

GameBoardView::~GameBoardView() {}

void GameBoardView::draw() {
    textcolor(BLACK, WHITE);

    int rows = board->getRow();
    int cols = board->getCol();

    int boxWidth = 50;
    int boxHeight = 25;     // player box�� ����
    
    // ���� ���� ���� ��ǥ(x, y) ���
    int boxX = (consoleWidth - boxWidth) / 2;       // 30
    int boxY = (consoleHeight - boxHeight) / 2;     // 7

    // ���� �׵θ� �׸���
    drawBoxFill(boxX, boxY, boxX + boxWidth - 1, boxY + boxHeight - 1, BLACK); 
   
    // ���� �׸��� ���Ŀ� ���� ��ġ ���
    // �� �� ������ 2ĭ(���� + ���� 1ĭ ����)
    int boardWidthInChars = cols * 2 - 1;
    int boardHeightInChars = rows;

    int startX = boxX + (boxWidth - boardWidthInChars) / 2; // �� �� ���� ���� ����
    int startY = boxY + (boxHeight - boardHeightInChars) / 2;   // �� ���� ���� ���� ����

    textcolor(WHITE, BLACK); // fc: white, bc: black

    // �ܾ� ���
    for (int y = 0; y < rows; y++) {    
        gotoxy(startX + 1, startY + y); // y�� �ٺ� ���
        for (int x = 0; x < cols; x++) {
            if (board->isHighlighted(y, x)) 
                textcolor(CYAN1, BLACK);
            else 
                textcolor(WHITE, BLACK);

            cout << board->getCharAt(y, x);
            if (x < cols - 1) cout << ' ';  // ĭ ���� ���� ���
        }
    }

    textcolor(BLACK, WHITE);   // ����
}

void GameBoardView::setBoard(GameBoard* board) { this-> board = board; }