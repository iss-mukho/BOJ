/**
 * ���� 12865: ����� �賶(��� V), https://www.acmicpc.net/problem/12865
 * Dynamic Programming + 0-1 Knapsack Algorithm
 *	- 0-1 Knapsack Algorithm: ���� �ɰ� �� ���� �賶 ����
 *	- Fractional: ���� �ɰ� �� �ִ� �賶 ����
 * 
 * ù ����: 1���� dp �迭, 2�� for���� ���� �����ظ� ������
 * 2���� DP ����: https://cocoon1787.tistory.com/206, https://gamedoridori.tistory.com/20
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
		for (int w = 1; w <= K; ++w) { // w = ���� ���� w
			if (w >= weights[n]) // ������ ���� �� �ִ� ���
				dp[n][w] = max(dp[n - 1][w], dp[n - 1][w - weights[n]] + values[n]);
			else
				dp[n][w] = dp[n - 1][w];
		}
	}
}
void output() {
	cout << dp[N][K] << '\n';
}