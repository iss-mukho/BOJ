// 백준 26091: 현대모비스 소프트웨어 아카데미(실버 I)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, a, low, high, answer;
vector<int> abil;

int main() {
	// 입력
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a);
		abil.push_back(a);
	}

	// 처리
	sort(abil.begin(), abil.end());
	low = 0, high = N - 1;
	while (low < high) {
		if (abil[low] + abil[high] < M) {
			++low;
			continue;
		}
		++answer;
		++low; --high;
	}

	// 출력
	printf("%d\n", answer);

	return 0;
}