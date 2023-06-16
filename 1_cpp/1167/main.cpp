// 백준 1167: 트리의 지름(골드 II), https://www.acmicpc.net/problem/1167
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 100001;

int V, answer = 0, maxNode = 0;
vector<pii> tree[MAX];
bool visited[MAX];

void input() {
	cin >> V;

	int start = 0, end = 0, dist = 0;
	for (int i = 0; i < V; ++i) {
		cin >> start;

		while (cin >> end && end != -1) {
			cin >> dist;
			tree[start].push_back(pii(end, dist));
		}
	}
}

void process(int start, int dist = 0) {
	visited[start] = true;

	if (answer < dist) {
		answer = dist;
		maxNode = start;
	}

	for (int i = 0; i < (signed)tree[start].size(); ++i) {
		int end = tree[start][i].first;
		if (!visited[end]) process(end, dist + tree[start][i].second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();

	process(1);
	fill_n(visited, MAX, false);
	process(maxNode);

	cout << answer << '\n';

	return 0;
}
