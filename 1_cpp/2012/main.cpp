// 백준 2012: 등수 매기기(실버 III)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, r;
long long answer = 0;
vector<int> Rank;

int main() {
	// 입력
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &r);
		Rank.push_back(r);
	}
	
	// 처리
	sort(Rank.begin(), Rank.end());
	for (int i = 1; i <= N; ++i)
		answer += abs(i - Rank[i-1]);
	
	// 출력
	printf("%lld\n", answer);

	return 0;
}