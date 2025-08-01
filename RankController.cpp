// RankController.cpp

#include "RankController.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<RankEntry> RankController::rank;

RankController::RankController() {}

RankController::~RankController() {}

void RankController::saveRank(int score, string name) {
	string timestamp = getCurrentDateTime();
	rank.push_back(RankEntry(score, name, timestamp));	// ����ü�� ����
	sort(rank.begin(), rank.end(), [](const RankEntry& a, const RankEntry& b) {return a.score > b.score;});		// ���� ���� �������� ����
}

string RankController::getCurrentDateTime() {
	time_t now = time(0);
	tm* local = localtime(&now);

	char buffer[100];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local);  // ���� ����

	return string(buffer);
}

void RankController::displayRank(const string& filename) {
	ofstream fout(filename);	// ����� ���

	if (!fout) {
		cout << filename << " ���� ���� ����" << endl;
		return;
	}

	fout << "===== RANKING =====" << endl << endl;
	
	for (int i = 0; i < rank.size(); i++) {		// ��ü ��ŷ �ٽ� �ۼ�
		fout << i + 1 << ". " << rank[i].name << " : " << rank[i].score << " (" << rank[i].date << ") " << endl;
	}

	fout.close();
}