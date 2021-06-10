// gg
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<vector<int>> cmp;
vector<int> idx;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, i, j, tempMax = 0, maxmin = 1000000001, minIdx;
	
	cin >> N >> M;
	cmp = vector<vector<int>>(N, vector<int>(M));
	idx = vector<int>(N, 0);
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j)
			cin >> cmp[i][j];
	}
	for (i = 0; i < N; ++i) {
		sort(cmp[i].begin(), cmp[i].end());
		tempMax = max(tempMax, cmp[i][0]);
		pq.push({ cmp[i][0], i });
	}

	for (i = 0; i < N * M - N; ++i) {
		ii cur = pq.top();
		minIdx = cur.second;
		maxmin = min(maxmin, tempMax - cur.first);

		if (idx[minIdx] == N - 1)
			break;
		else {
			pq.pop();
			++idx[minIdx];
			tempMax = max(tempMax, cmp[minIdx][idx[minIdx]]);
			pq.push({ cmp[minIdx][idx[minIdx]], minIdx });
		}
	}
	cout << maxmin << '\n';
	return 0;
}