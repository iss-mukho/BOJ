#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int INF = 987654321;
const int MAX = 101;

int n, m, r, a, b, l, answer = 0;
int item[MAX], dist[MAX];
vector<pii> graph[MAX];

void dijkstra(int start) {
	priority_queue<pii> pq;
	pq.push(pii(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int c = pq.top().second;
		int cd = -pq.top().first;
		pq.pop();

		if (dist[c] < cd) continue;

		for (pii nxt : graph[c]) {
			int nc = nxt.second;
			int nd = cd + nxt.first;

			if (nd > m) continue;
			if (dist[nc] < nd) continue;

			dist[nc] = nd;

			pq.push(pii(-nd, nc));
		}
	}
}

int getAnswer() {
	int result = 0;

	for (int i = 1; i <= n; ++i)
		if (dist[i] != INF)
			result += item[i];

	return result;
}

int main() {
	scanf("%d %d %d", &n, &m, &r);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &item[i]);

	for (int i = 0; i < r; ++i) {
		scanf("%d %d %d", &a, &b, &l);

		graph[a].push_back(pii(l, b));
		graph[b].push_back(pii(l, a));
	}

	for (int i = 1; i <= n; ++i) {
		fill_n(dist, n + 1, INF);

		dijkstra(i);

		answer = max(answer, getAnswer());
	}

	printf("%d\n", answer);

	return 0;
}