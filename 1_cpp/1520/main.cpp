// 백준 1520: 내리막 길(골드 III), https://www.acmicpc.net/problem/1520
// BFS + Priority Queue도 가능
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAX = 500;
const int dx[4] = { -1, +1, +0, +0 };
const int dy[4] = { +0, +0, -1, +1 };

int N, M;
int jido[MAX][MAX];
int dp[MAX][MAX];

bool inRange(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}

int DFS(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];

	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];

		if (!inRange(nx, ny)) continue;
		if (jido[x][y] <= jido[nx][ny]) continue;

		cnt += DFS(nx, ny);
	}

	dp[x][y] = cnt;
	return dp[x][y];
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &jido[i][j]);
	for (int i = 0; i < N; ++i)
		fill_n(dp[i], M, -1);
	
	dp[N - 1][M - 1] = 1;
	cout << DFS(0, 0) << '\n';

	return 0;
}
