// Why 출력초과..? why long long..? -> 아 500*6000*10000
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; // <A, B>
typedef pair<pii, int> edge; // <<A, B>, C>
const int MAX = 500;
const ll INF = 30000000001;

int N, M, A, B, C;
ll dist[MAX + 1];
vector<edge> edges;
deque<int> dq;

void init();
bool ballmanFord(int start);
void input();
void output();

int main() {
	input();
	if (ballmanFord(1))
		output();
	else
		printf("%d\n", -1);

	return 0;
}

void init() {
	fill_n(dist + 1, N, INF);
}
void input() {
	scanf("%d %d", &N, &M);
	init();

	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &A, &B,  &C);
		edges.push_back(edge(pii(A, B), C));
	}

}
bool ballmanFord(int start) {
	dist[start] = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int curNode = edges[j].first.first;
			int nextNode = edges[j].first.second;
			int weight = edges[j].second;

			ll nextWeight = dist[curNode] + weight;
			if (dist[curNode] != INF && dist[nextNode] > nextWeight) {
				dist[nextNode] = nextWeight;

				if (i == N - 1)
					return false;
			}
		}
	}

	return true;
}
void output() {
	for (int i = 2; i <= N; ++i) {
		if (dist[i] == INF)
			printf("%d\n", -1);
		else
			printf("%lld\n", dist[i]);
	}
}