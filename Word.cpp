// Word.cpp

#include <algorithm>
#include "Word.h"

Word::Word(string text) {
	this->text = text;
	startX = 10, startY = 10;	
	direction = HORIZONTAL;	
	found = false;
}

WordView& Word::getWordView() {
	return wordView;
}

void Word::setPosition(int x, int y, Direction direction) {
	this->startX = x;
	this->startY = y;
	this->direction = direction;
}

const string& Word::getText() { 
	return text; 
}

int Word::getX() {
	return startX;
}

int Word::getY() {
	return startY;
}

Direction Word::getDirection() { 
	return direction;
}

bool Word::isFound() {
	return found;
}

void Word::markFoundWord() {
	found = true;
}