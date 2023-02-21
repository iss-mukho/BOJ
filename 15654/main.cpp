// 백준 15654: N과 M (5)(실버 III), https://www.acmicpc.net/problem/15654
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;
int N, M, number;
bool checked[MAX];
vector<int> numbers;
vector<int> output;

void print() {
	for (auto o : output)
		printf("%d ", o);
	printf("\n");
}
void Back(int cnt) {
	if (cnt == M) {
		print();
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (checked[i]) continue;

		checked[i] = true;
		output.push_back(numbers[i]);
		Back(cnt + 1);
		checked[i] = false;
		output.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &number);
		numbers.push_back(number);
	}
	sort(numbers.begin(), numbers.end());

	Back(0);

	return 0;
}