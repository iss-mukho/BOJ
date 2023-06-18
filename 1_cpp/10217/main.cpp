// 백준 10217: KCM Travel(플래티넘 V), https://www.acmicpc.net/problem/10217
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
using namespace std;

struct info {
	int destination;
	int cost;
	int time;

	info(int d, int c, int t) : destination(d), cost(c), time(t) {}

	bool operator<(const info& o) const {
		return time > o.time;
	}
};

const int INF = 1000000000;

int T;
int N, M, K;
int u, v, c, d;
array<vector<info>, 101> graph;
array<array<int, 10001>, 101> dist;

void input() {
	int _ = scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; ++i) graph[i].clear();

	for (int i = 0; i < K; ++i) {
		int _ = scanf("%d %d %d %d", &u, &v, &c, &d);
		graph[u].emplace_back(info(v, c, d));
	}
}

void init() {
	for (int i = 0; i <= M; ++i)
		dist[1][i] = 0;

	for (int i = 1; i <= N; ++i)
		for (int j = 0; j <= M; ++j)
			dist[i][j] = INF;
}

void dijkstra() {
	priority_queue<info> pq;
	pq.emplace(info(1, 0, 0));

	while (!pq.empty()) {
		info front = pq.top(); pq.pop();
		int s = front.destination;
		int c = front.cost;
		int t = front.time;

		if (dist[s][c] < t) continue;

		for (info& nextInfo : graph[s]) {
			int e = nextInfo.destination;
			int nc = c + nextInfo.cost;
			int nt = t + nextInfo.time;

			int i;
			for (i = nc; i <= M && dist[e][i] > nt; ++i) dist[e][i] = nt;
			if (i > nc) pq.emplace(info(e, nc, nt));
		}
	}
}

void output() {
	int answer = dist[N][M];
	if (answer == INF) printf("%s\n", "Poor KCM");
	else printf("%d\n", answer);
}

int main() {
	int _ = scanf("%d", &T);

	while (T--) {
		input();
		init();
		dijkstra();
		output();
	}

	return 0;
}