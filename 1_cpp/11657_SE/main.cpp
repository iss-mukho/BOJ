#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;

const int MAX = 501;
const ll INF = 30000000001;

int N, M, A, B, C;
ll dist[MAX];
vector<pip> edge;

bool bellmanFord() {
	dist[1] = 0;

	for (int i = 1; i <= N; ++i) {
		for (pip e : edge) {
			int start = e.first.first;
			int end = e.first.second;
			int weight = e.second;

			if (dist[start] == INF) continue;
			if (dist[end] <= dist[start] + weight) continue;

			dist[end] = dist[start] + weight;
			if (i == N) return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	fill_n(dist, N + 1, INF);

	for (int i = 0; i < M; ++i) {
		cin >> A >> B >> C;
		edge.push_back(pip(pii(A, B), C));
	}

	if (bellmanFord()) {
		for (int i = 2; i <= N; ++i)
			cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
	}
	else {
		cout << "-1\n";
	}

	return 0;
}