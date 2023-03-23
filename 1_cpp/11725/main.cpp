// 백준 11725: 트리의 부모 찾기(실버 II), https://www.acmicpc.net/problem/11725
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

const int MAX = 100000;
int N, h, l;
vector<int> graph[MAX + 1];
bool visited[MAX + 1];
int parent[MAX + 1];

void BFS(int start) {
	deque<int> dq;
	visited[start] = true;
	dq.push_back(start);

	while (!dq.empty()) {
		h = dq.front();
		dq.pop_front();

		for (auto l : graph[h]) {
			if (visited[l]) continue;

			visited[l] = true;
			parent[l] = h;
			dq.push_back(l);
		}
	}
}

int main() {
	// 입력
	scanf("%d", &N);

	for (int i = 0; i < N - 1; ++i) {
		scanf("%d %d", &h, &l);
		graph[h].push_back(l);
		graph[l].push_back(h);
	}

	// 처리
	BFS(1);

	// 출력
	for (int i = 2; i <= N; ++i)
		printf("%d\n", parent[i]);

	return 0;
}