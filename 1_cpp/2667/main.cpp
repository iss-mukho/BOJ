// 백준 2667: 단지번호붙이기(실버 I), https://www.acmicpc.net/problem/2667
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 25;

int N;
char inputLine[MAX + 1];
int arr[MAX][MAX];
bool visited[MAX][MAX];
vector<int> answer;

// U, D, L, R
int dx[4] = { -1, +1, +0, +0 };
int dy[4] = { +0, +0, -1, +1 };
bool inRange(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < N)
		return true;
	return false;
}

int BFS(pii start) {
	deque<pii> dq;
	dq.push_back(start);
	visited[start.first][start.second] = true;

	int count = 1;
	while (!dq.empty()) {
		int cx = dq.front().first;
		int cy = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!inRange(nx, ny)) continue;
			if (arr[nx][ny] == 0) continue;
			if (visited[nx][ny]) continue;
			
			visited[nx][ny] = true;
			dq.push_back(pii(nx, ny));
			++count;
		}
	}

	return count;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", &inputLine);
		for (int j = 0; j < N; ++j)
			arr[i][j] = inputLine[j] - '0';
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == 0) continue;
			if (visited[i][j]) continue;

			answer.push_back(BFS(pii(i, j)));
		}
	}

	sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for (auto &a : answer)
		printf("%d\n", a);

	return 0;
}
