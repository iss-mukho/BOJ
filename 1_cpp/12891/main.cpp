// 백준 12891: DNA 비밀번호(실버 II), https://www.acmicpc.net/problem/12891
#include <iostream>
#include <string>
#include <map>
using namespace std;

int S, P, A, C, G, T, answer = 0;
string DNA;
map<char, int> dnaCount;

void init() {
	dnaCount['A'] = 0;
	dnaCount['C'] = 0;
	dnaCount['G'] = 0;
	dnaCount['T'] = 0;
}

void input() {
	cin >> S >> P;
	cin >> DNA;
	cin >> A >> C >> G >> T;
}

bool check() {
	return dnaCount['A'] >= A && dnaCount['C'] >= C && dnaCount['G'] >= G && dnaCount['T'] >= T;
}

void solution() {
	int start = 0, end = P;
	for (int i = start; i < end; ++i) {
		if (dnaCount.find(DNA[i]) == dnaCount.end()) continue;
 		++dnaCount[DNA[i]];
	}
	if (check()) ++answer;
	while (end < S) {
		--dnaCount[DNA[start++]];
		++dnaCount[DNA[end++]];
		if (check()) ++answer;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	input();
	solution();
	cout << answer << '\n';

	return 0;
}
