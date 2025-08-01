#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>
#include "View.h"
using namespace std;

class ConfigurationView : public View {
public:
	ConfigurationView();
	~ConfigurationView();
	void draw();
	//void prepareInput();
};

#endif // !CONFIGURATION_H

