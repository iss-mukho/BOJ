#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> Dot;
const int MAX = 8;
const int dx[4] = { -1, +1, +0, +0 };
const int dy[4] = { +0, +0, -1, +1 };

int N, M, answer = 0;
int graph[MAX][MAX], copyGraph[MAX][MAX];
bool visited[MAX][MAX];

bool inRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

void input() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &graph[i][j]);
}

void setCopyGraph() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			copyGraph[i][j] = graph[i][j];
}

void initVisited() {
	for (int i = 0; i < N; ++i)
		fill_n(visited[i], M, false);
}

void moveVirus(Dot start) {
	queue<Dot> q;
	q.push(start);
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		Dot cur = q.front();
		q.pop();

		int cx = cur.first, cy = cur.second;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!inRange(nx, ny)) continue;
			if (copyGraph[nx][ny] == 1) continue;
			if (visited[nx][ny]) continue;

			copyGraph[nx][ny] = 2;
			q.push(Dot(nx, ny));
			visited[nx][ny] = true;
		}
	}
}

void findVirus() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (copyGraph[i][j] != 2) continue;
			if (visited[i][j]) continue;
			moveVirus(Dot(i, j));
		}
	}
}

int getSafeAreaSize() {
	int safeAreaSize = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (copyGraph[i][j] == 0) ++safeAreaSize;

	return safeAreaSize;
}

void setWall(int wallCount) {
	if (wallCount == 3) {
		setCopyGraph();
		initVisited();

		findVirus();
		answer = max(answer, getSafeAreaSize());
		return;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (graph[i][j] != 0) continue;
			
			graph[i][j] = 1;
			setWall(wallCount + 1);
			graph[i][j] = 0;
		}
	}
}

int main() {
	input();
	setWall(0);
	printf("%d\n", answer);

	return 0;
}