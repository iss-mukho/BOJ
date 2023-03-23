/**
 * 백준 12865: 평범한 배낭(골드 V), https://www.acmicpc.net/problem/12865
 * Dynamic Programming + 0-1 Knapsack Algorithm
 *	- 0-1 Knapsack Algorithm: 짐을 쪼갤 수 없는 배낭 문제
 *	- Fractional: 짐을 쪼갤 수 있는 배낭 문제
 * 
 * 첫 접근: 1차원 dp 배열, 2중 for문을 통해 최적해를 구하자
 * 2차원 DP 참고: https://cocoon1787.tistory.com/206, https://gamedoridori.tistory.com/20
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int nMax = 101;
const int weightMax = 100001;

int N, K, W, V;
int weights[nMax], values[nMax], dp[nMax][weightMax];

void input();
void solution();
void output();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solution();
	output();

	return 0;
}

void input() {
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) 
		cin >> weights[i] >> values[i];
}
void solution() {
	for (int n = 1; n <= N; ++n) {
		for (int w = 1; w <= K; ++w) { // w = 무게 제한 w
			if (w >= weights[n]) // 물건을 넣을 수 있는 경우
				dp[n][w] = max(dp[n - 1][w], dp[n - 1][w - weights[n]] + values[n]);
			else
				dp[n][w] = dp[n - 1][w];
		}
	}
}
void output() {
	cout << dp[N][K] << '\n';
}