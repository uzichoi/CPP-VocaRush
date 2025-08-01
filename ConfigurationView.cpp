#include "ConfigurationView.h"
#include "InputController.h"
#include "KeyCodes.h"

ConfigurationView::ConfigurationView() {}

ConfigurationView::~ConfigurationView() {}

void ConfigurationView::draw() {
	cls(15, 0);

	int boxWidth = 60, boxHeight = 13;
	int boxX = (this->consoleWidth - boxWidth) / 2;
	int boxY = (this->consoleHeight - boxHeight) / 2;

	drawBox(boxX, boxY, boxX + boxWidth - 1, boxY + boxHeight - 1);

	textcolor(3, 15);
	string configurationMsg = "< Configuration >";
	int textX = consoleWidth / 2 - configurationMsg.length() / 2;
	gotoxy(textX, boxY - spacingBetweenLines);
	cout << configurationMsg;

	textcolor(0, 15);	// fc: black, bg: white
	gotoxy(boxX + 5, boxY + spacingBetweenLines);
	cout << "Input Player 1's name  >> ";
	gotoxy(boxX + 5, boxY + spacingBetweenLines * 2);
	cout << "Input Player 2's name  >> ";
	gotoxy(boxX + 5, boxY + spacingBetweenLines * 3);
	cout << "Input Board Size(5~10) >> ";
	
	string continueMsg = "Press ENTER to continue...";
	textX = (int)(consoleWidth / 2 - continueMsg.length() / 2);
	gotoxy(textX, boxY + boxHeight + spacingBetweenLines);
	textcolor(2, 15);
	cout << continueMsg;
	textcolor(0, 15);   // ฟ๘บน
}
