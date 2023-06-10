// 백준 3015: 오아시스 재결합(플래티넘 V), https://www.acmicpc.net/problem/3015
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, height, sameHeightCount = 0;
ll pairCount = 0;
stack<pii> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> height;
		
		sameHeightCount = 1;
		while (!s.empty() && s.top().first < height) {
			pairCount += s.top().second;
			s.pop();
		}

		if (!s.empty()) {
			if (s.top().first != height) ++pairCount;
			else {
				pairCount += s.top().second;
				sameHeightCount = s.top().second + 1;
				if (s.size() > 1) ++pairCount;
				s.pop();
			}
		}
		
		s.push(pii(height, sameHeightCount));
	}

	cout << pairCount << '\n';

	return 0;
}
