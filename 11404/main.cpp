#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1000000000001; // 최악의 경우: 100 * 100000 * 100000 = 1조(int형 최대값인 21억 초과)
const int MAX = 100;
int n, m, a, b, c;
ll city[MAX + 1][MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력1
	cin >> n;
	cin >> m;

	// 초기화1
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			city[i][j] = INF;
	// 초기화2: 시작 도시와 도착 도시가 같은 경우는 없다.
	for (int i = 1; i <= n; ++i)
		city[i][i] = 0;

	// 입력2
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		// 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
		if(city[a][b] > c)
			city[a][b] = c;
	}

	// 플로이드-워셜
	for (int x = 1; x <= n; ++x)
		for (int s = 1; s <= n; ++s)
			for (int e = 1; e <= n; ++e)
				city[s][e] = min(city[s][e], city[s][x] + city[x][e]);

	// 출력
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (city[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << city[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}