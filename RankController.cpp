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
	rank.push_back(RankEntry(score, name, timestamp));	// 구조체로 저장
	sort(rank.begin(), rank.end(), [](const RankEntry& a, const RankEntry& b) {return a.score > b.score;});		// 점수 기준 내림차순 정렬
}

string RankController::getCurrentDateTime() {
	time_t now = time(0);
	tm* local = localtime(&now);

	char buffer[100];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local);  // 포맷 지정

	return string(buffer);
}

void RankController::displayRank(const string& filename) {
	ofstream fout(filename);	// 덮어쓰기 모드

	if (!fout) {
		cout << filename << " 파일 열기 실패" << endl;
		return;
	}

	fout << "===== RANKING =====" << endl << endl;
	
	for (int i = 0; i < rank.size(); i++) {		// 전체 랭킹 다시 작성
		fout << i + 1 << ". " << rank[i].name << " : " << rank[i].score << " (" << rank[i].date << ") " << endl;
	}

	fout.close();
}