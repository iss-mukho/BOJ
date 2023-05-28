// 백준 1948: 임계경로(플래티넘 V), https://www.acmicpc.net/problem/1948
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 10001;

int N, M, s, e, answer = 0;
int entry[MAX], time_[MAX];
bool visited[MAX];
vector<pii> road[MAX], reverseRoad[MAX];

void findDist() {
	deque<pii> dq;
	dq.push_back(pii(s, 0));

	while (!dq.empty()) {
		int c = dq.front().first;
		int ct = dq.front().second;
		dq.pop_front();

		for (auto &next : road[c]) {
			int n = next.first;
			int nt = next.second;

			time_[n] = max(time_[n], ct + nt);
			--entry[n];

			if (!entry[n]) dq.push_back(pii(n, time_[n]));
		}
	}
}

void findLongest() {
	deque<int> dq;
	dq.push_back(e);
	visited[e] = true;

	while (!dq.empty()) {
		int c = dq.front();
		dq.pop_front();

		for (auto& pre : reverseRoad[c]) {
			int p = pre.first;
			int pt = pre.second;

			if (time_[c] - pt != time_[p]) continue;
			++answer;
			if (visited[p]) continue;
			visited[p] = true;
			dq.push_back(p);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back(pii(b, c));
		reverseRoad[b].push_back(pii(a, c));
		++entry[b];
	}

	cin >> s >> e;

	findDist();
	findLongest();

	cout << time_[e] << '\n' << answer << '\n';

	return 0;
}
