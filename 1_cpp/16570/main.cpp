// 백준 16570: 앞뒤가 맞는 수열(플래티넘 V), https://www.acmicpc.net/problem/16570
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int N, n;
int number[MAX];
int failTable[MAX] = { 0, };
int maxK = 0, kCount = 0;

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> number[i];
}

void calcFailTable() {
	int i = 0;
	for (int j = 1; j < N; ++j) {
		while (i > 0 && number[i] != number[j]) i = failTable[i - 1];
		if (number[i] == number[j]) failTable[j] = ++i;
	}
}

void calcAnswer() {
	for (int i = 1; i < N; ++i) {
		if (maxK > failTable[i]) continue;

		if (maxK == failTable[i]) {
			++kCount;
			continue;
		}

		maxK = failTable[i];
		kCount = 1;
	}
}

void output() {
	if (maxK == 0) {
		cout << -1 << '\n';
		return;
	}
	cout << maxK << ' ' << kCount << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();

	reverse(number, number + N);
	calcFailTable();
	
	calcAnswer();
	output();

	return 0;
}