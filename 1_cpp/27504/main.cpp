// 백준 27504: 상대음감의 노래찾기(플래티넘 V), https://www.acmicpc.net/problem/27504
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1000000;

int N, K, m, L;
vector<int> melody;
vector<vector<int>> texts;
vector<int> pattern;
int failTable[MAX];
vector<int> answer;

bool KMP(vector<int> &text, vector<int> &pattern) {
	int j = 0;
	for (int i = 1; i < (signed)pattern.size(); ++i) {
		while (j > 0 && pattern[i] != pattern[j])
			j = failTable[j - 1];
		if (pattern[i] == pattern[j])
			failTable[i] = ++j;
	}

	j = 0;
	for (int i = 0; i < (signed)text.size(); ++i) {
		while (j > 0 && text[i] != pattern[j])
			j = failTable[j - 1];
		if (text[i] == pattern[j]) {
			++j;
			if (j == (signed)pattern.size())
				return true;
		}
	}

	return false;
}

vector<int> getPreprocessMelody(vector<int> &v){
    vector<int> pre;
    for(int i = 0; i < (signed)v.size() - 1; ++i)
        pre.push_back(v[i] - v[i + 1]);
    return pre;
}

void input() {
	int _ = scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		_ = scanf("%d", &K);
		for (int j = 0; j < K; ++j) {
			_ = scanf("%d", &m);
			melody.push_back(m);
		}
		texts.push_back(getPreprocessMelody(melody));
		melody.clear();
	}
	
	_ = scanf("%d", &L);
	for (int i = 0; i < L; ++i) {
		_ = scanf("%d", &m);
		melody.push_back(m);
		pattern = getPreprocessMelody(melody);
	}
}

void process() {
	for (int i = 0; i < N; ++i) {
		if (KMP(texts[i], pattern))
			answer.push_back(i + 1);
		fill_n(failTable, L, 0);
	}		
}

void output() {
	if (answer.empty()) {
		printf("-1\n");
		return;
	}
		
	for (auto& a : answer)
		printf("%d ", a);
	printf("\n");
}

int main() {
	input();
	process();
	output();
	
	return 0;
}
