#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int INF = 100000000;
const int MAX = 1001;

int N, M, X, s, e, t, answer = 0;
int dist[MAX], reverseDist[MAX];
vector<pii> graph[MAX];
vector<pii> reverseGraph[MAX];
priority_queue<pii> pq;

void dijkstra(int start, vector<pii> *graph, int* dist) {
	pq.push(pii(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int c = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		
		if (dist[c] < d) continue;

		for (pii nxt : graph[c]) {
			int n = nxt.second;
			int nd = d + nxt.first;

			if (dist[n] < nd) continue;
			dist[n] = nd;
			pq.push(pii(-nd, n));
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &X);

	fill_n(dist, N + 1, INF);
	fill_n(reverseDist, N + 1, INF);

	for (int i = 0;i < M;++i) {
		scanf("%d %d %d", &s, &e, &t);
		graph[s].push_back(pii(t, e));
		reverseGraph[e].push_back(pii(t, s));
	}
	
	dijkstra(X, graph, dist);
	dijkstra(X, reverseGraph, reverseDist);

	for (int i = 1; i <= N; ++i) {
		if (i == X) continue;
		answer = max(answer, dist[i] + reverseDist[i]);
	}
		
	printf("%d\n", answer);

	return 0;
}