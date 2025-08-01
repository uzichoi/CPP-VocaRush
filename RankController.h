// RankController.h

#ifndef RANKCONTROLLER_H
#define RANKCONTROLLER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

struct RankEntry {
	int score;	// 점수
	string name;	// 이름
	string date;	// 날짜

	RankEntry(int s, string n, string d) : score(s), name(n), date(d) {}
};

class RankController {
	static vector<RankEntry> rank;		
public:
	RankController();
	~RankController();
	void saveRank(int score, string name);
	string getCurrentDateTime();
	void displayRank(const string& filename);
};

#endif // !RANKCONTROLLER_H
