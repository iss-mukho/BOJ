// 백준 16928: 뱀과 사다리 게임(골드 V), https://www.acmicpc.net/problem/16928
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <deque>
using namespace std;
const int MAX = 101;

int N, M, a, b;
int ladderOrSnake[MAX], visited[MAX];

void BFS() {
	deque<int> dq;
	dq.push_back(1);
	visited[1] = 0;

	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		for (int i = 1; i <= 6; ++i) {
			int next = cur + i;

			if (next > 100) continue;
			if (ladderOrSnake[next] != 0) next = ladderOrSnake[next];
			if (visited[next] < visited[cur] + 1) continue;

			dq.push_back(next);
			visited[next] = visited[cur] + 1;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N + M; ++i) {
		scanf("%d %d", &a, &b);
		ladderOrSnake[a] = b;
	}

	fill_n(visited, MAX, MAX);
	BFS();

	printf("%d\n", visited[100]);

	return 0;
}
