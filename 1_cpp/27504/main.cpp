// 백준 27504: 상대음감의 노래찾기(플래티넘 V), https://www.acmicpc.net/problem/27504
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

int N, K, n, L;
vector<int> kText;
vector<vector<int>> texts;
vector<int> pattern;
int failTable[MAX];
vector<int> answer;

bool KMP(vector<int> text, vector<int> &pattern) {
	int j = 0;
	for (int i = 1; i < L; ++i) {
		while (j > 0 && pattern[i] != pattern[j])
			j = failTable[j - 1];
		if (pattern[i] == pattern[j])
			failTable[i] = ++j;
	}

	int base = text[0];
	j = 0;
	for (int i = 0; i < (signed)text.size(); ++i) {
		int conv = text[i] - base + 1;

		while (j > 0 && conv != pattern[j]) {
			j = failTable[j - 1];
			base = text[i + j] - pattern[j] + 1; // base 값 재조정
			conv = text[i] - base + 1; // 상대적인 크기 다시 계산
		}
			
		if (conv == pattern[j]) {
			++j;
			if (j == (signed)pattern.size())
				return true;
		}
	}

	return false;
 }

void input() {
	int _ = scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		_ = scanf("%d", &K);
		for (int j = 0; j < K; ++j) {
			_ = scanf("%d", &n);
			kText.push_back(n);
		}
		texts.push_back(kText);
		kText.clear();
	}
	
	_ = scanf("%d", &L);
	for (int i = 0; i < L; ++i) { 
		_ = scanf("%d", &n);
		pattern.push_back(n);
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
		
	for (auto& n : answer)
		printf("%d ", n);
	printf("\n");
}

int main() {
	input();
	process();
	output();
	
	return 0;
}
