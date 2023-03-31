// 백준 1926: 그림(실버 I), https://www.acmicpc.net/problem/1926
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <deque>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 500;
const int dx[4] = { -1, +1, +0, +0 };
const int dy[4] = { +0, +0, -1, +1 };

int n, m, imageCount = 0, maxArea = 0;
int paper[MAX][MAX];
bool visited[MAX][MAX];

bool inRange(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < m)
		return true;
	return false;
}

int BFS(pii start) {
	int area = 1;

	deque<pii> dq;
	visited[start.first][start.second] = true;
	dq.push_back(start);

	while (!dq.empty()) {
		int cx = dq.front().first, cy = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (!inRange(nx, ny)) continue;
			if (!paper[nx][ny]) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = true;
			dq.push_back(pii(nx, ny));
			++area;
		}
	}

	return area;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &paper[i][j]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!paper[i][j]) continue;
			if (visited[i][j]) continue;
			++imageCount;
			maxArea = max(maxArea, BFS(pii(i, j)));
		}
	}
		
	printf("%d\n%d\n", imageCount, maxArea);

	return 0;
}
