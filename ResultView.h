#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include "View.h"

class ResultView : public View {
public:
	void draw();
	void draw(int index, string name, int score);
};

#endif