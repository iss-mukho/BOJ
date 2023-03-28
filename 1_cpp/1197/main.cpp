// 백준 1198: 최소 스패닝 트리(골드 IV), https://www.acmicpc.net/problem/1197
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 100000;

int V, E, A, B, C, answer = 0;
bool visited[MAX + 1];
vector<pii> graph[MAX + 1];

void prim() {
	priority_queue<pii> pq;

	visited[1] = true;
	for (auto& next : graph[1])
		pq.push(pii(-next.first, next.second));

	while (!pq.empty()) {
		int start = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();

		if (visited[start]) continue;
		visited[start] = true;
		answer += weight;

		for (auto& next : graph[start]) {
			int end = next.second;
			int endWeight = next.first;

			if (visited[end]) continue;
			pq.push(pii(-endWeight, end));
		}
	}
}

int main() {
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &A, &B, &C);

		graph[A].push_back(pii(C, B));
		graph[B].push_back(pii(C, A));
	}

	prim();

	printf("%d\n", answer);

	return 0;
}