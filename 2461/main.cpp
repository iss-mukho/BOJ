#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq[1000];
vector<int> cmp;
vector<int> t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, i, j, input, temp, tempMin = 1001, minIdx, maxmin = 1000, tempMaxMin, tempMinIdx, tempMin_;
	// 입력
	cin >> N >> M;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			cin >> input;
			pq[i].push(input);
		}
	}
	// 초기값
	for (i = 0; i < N; ++i) {
		temp = pq[i].top();
		if (temp < tempMin) {
			tempMin = temp;
			minIdx = i;
		}
		pq[i].pop();
		cmp.push_back(temp);
	}
	t.resize((int)(cmp.size()));
	copy(cmp.begin(), cmp.end(), t.begin());
	while (!t.empty()) {
		tempMin_ = *min_element(t.begin(), t.end());
		if (tempMin_ == 1001)
			break;

		tempMaxMin = *max_element(cmp.begin(), cmp.end()) - *min_element(cmp.begin(), cmp.end());
		if (tempMaxMin < maxmin)
			maxmin = tempMaxMin;

		if (!pq[minIdx].empty()) {
			cmp[minIdx] = pq[minIdx].top();
			pq[minIdx].pop();
			if (pq[minIdx].empty()) {
				t[minIdx] = 1001;
			}
			minIdx = min_element(cmp.begin(), cmp.end()) - cmp.begin();
		}
		else {
			tempMinIdx = min_element(t.begin(), t.end()) - t.begin();
			cmp[tempMinIdx] = *min_element(t.begin(), t.end());
			if (pq[tempMinIdx].empty())
				t[tempMinIdx] = 1001;
			else
				pq[tempMinIdx].pop();
		}
	}
	cout << maxmin << '\n';
	return 0;
}