#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii; // (v, w) or (w, edge)
const ll INF = 60000000001;
const int MAX = 20000;

int V, E, K, u, v, w;
ll dist[MAX + 1];
vector<pii> edges[MAX + 1];
priority_queue<pii> pq;

void dijkstra(int K) {
	dist[K] = 0;

	pq.push(pii(-0, K));
	while (!pq.empty()) {
		ll start = pq.top().second;
		ll weight = -pq.top().first;
		pq.pop();

		if (dist[start] < weight)
			continue;

		for (int j = 0; j < edges[start].size(); ++j) {
			ll end = edges[start][j].first;
			ll endWeight = edges[start][j].second;

			ll cost = weight + endWeight;
			if (dist[end] > cost) {
				dist[end] = cost;
				pq.push(pii(-cost, end));
			}
		}		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	cin >> K;

	fill_n(dist + 1, V, INF);
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		edges[u].push_back(pii(v, w));
	}

	dijkstra(K);

	for (int i = 1; i <= V; ++i) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}

	return 0;
}