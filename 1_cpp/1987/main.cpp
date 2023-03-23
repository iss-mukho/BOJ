#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;

const int MAX = 20;

int R, C, answer = 0;
bool isAlpha[26];
char graph[MAX + 5][MAX + 5];
bool visited[MAX][MAX];

// U, D, L, R
int dx[4] = { +0, +0, -1, +1 };
int dy[4] = { -1, +1, +0, +0 };
bool inRange(int x, int y) {
	if (0 <= x && x < R && 0 <= y && y < C)
		return true;
	return false;
}

void dfs(int x, int y, int cnt) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];

		if (!inRange(nx, ny)) continue;
		if (visited[nx][ny]) continue;
		if (isAlpha[graph[nx][ny] - 'A']) continue;

		visited[nx][ny] = true;
		isAlpha[graph[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		visited[nx][ny] = false;
		isAlpha[graph[nx][ny] - 'A'] = false;
	}
	
	if (answer < cnt)
		answer = cnt;
	return;
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; ++i)
		scanf("%s", &graph[i]);
	
	visited[0][0] = true;
	isAlpha[graph[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	printf("%d\n", answer);

	return 0;
}