// 크루스칼
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;
const int MAX = 1000;
int N, M, u, v, d, connection = 0, dist = 0;
int parent[MAX + 1];
char s;
vector<char> sex(MAX + 1);
vector<edge> edges;

int findParent(int x) {
	if (parent[x] != x)
		parent[x] = findParent(parent[x]);
	return parent[x];
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	// 입력
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i) {
		scanf(" %c", &s);
		sex[i] = s;
	}
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &d);
		edges.push_back(edge(d, pii(u, v)));
	}

	// 초기화
	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	// 처리: 크루스칼 알고리즘
	sort(edges.begin(), edges.end());
	for (auto e : edges) {
		u = e.second.first, v = e.second.second;
		d = e.first;

		if (sex[u] == sex[v]) continue;
		if (findParent(u) != findParent(v)) {
			unionParent(u, v);
			dist += d;
			++connection;
		}
	}

	// 출력
	if (connection == N - 1)
		printf("%d\n", dist);
	else
		printf("%d\n", -1);

	return 0;
}
#endif
// 프림
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // <-d, v>
const int MAX = 1000;
int N, M, u, v, d, connection = 0, dist = 0;
bool visited[MAX + 1];
char s;
vector<char> sex(MAX + 1);
vector<pii> edges[MAX + 1];
priority_queue<pii> pq;

void prim(int start) {
	visited[start] = true;

	for (auto end : edges[start]) {
		if (sex[start] == sex[end.second]) continue;
		pq.push(pii(-end.first, end.second));
	}
		
	while (!pq.empty()) {
		int w = -pq.top().first, s = pq.top().second;
		pq.pop();

		if (visited[s]) continue;
		visited[s] = true;
		++connection;
		dist += w;

		for (auto next : edges[s]) {
			int ew = next.first, e = next.second;

			if (sex[s] == sex[e]) continue;
			if(!visited[e])
				pq.push(pii(-ew, e));
		}
	}
}

int main() {
	// 입력
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i) {
		scanf(" %c", &s);
		sex[i] = s;
	}
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &d);
		edges[u].push_back(pii(d, v));
		edges[v].push_back(pii(d, u));
	}

	// 처리: 프림 알고리즘
	for (int i = 1; i <= N; ++i) {
		if (edges[i].size() == 0) continue;

		prim(i);
		break;
	}

	// 출력
	if (connection == N - 1)
		printf("%d\n", dist);
	else
		printf("%d\n", -1);

	return 0;
}
#endif