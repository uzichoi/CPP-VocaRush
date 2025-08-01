#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <iostream>
#include "View.h"
using namespace std;

class MenuView : public View {
public:
	MenuView();
	void draw();
	~MenuView();
};

#endif // !MENUVIEW_H