// PlayerView.h

#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "View.h"
#include "Player.h"
#include <string>
using namespace std;

class PlayerView : public View {
public:
	void draw();
	void draw(int index, Player& player);	// overload
	void draw(int index, Player& player, bool isActive);
};

#endif // !PLAYERVIEW_H
