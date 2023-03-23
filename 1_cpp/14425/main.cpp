// 백준 14425: 문자열 집합(실버 III), https://www.acmicpc.net/problem/14425
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <map>
using namespace std;

typedef pair<string, int> psi;

int N, M, answer = 0;
char str[505];
map<string, int> S;

int main() {
	// 입력 1
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		scanf("%s", &str);
		S.insert(psi(str, 0));
	}

	// 입력 2 + 처리
	for (int i = 0; i < M; ++i) {
		scanf("%s", &str);
		if (S.find(str) != S.end())
			++answer; // ++S[str]; // 풀이 2, 3
	}

	/*
	for (auto &s : S) {
		answer += S[s.first]; // 풀이 2
		answer += s.second; // 풀이 3
	}*/

	// 출력
	printf("%d\n", answer);

	return 0;
}