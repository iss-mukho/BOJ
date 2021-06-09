#include <iostream>
#include <deque>
using namespace std;
deque<int> cq;
int m[50];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, i, j, idx, cnt = 0;
	cin >> N >> M;
	for (i = 0; i < M; ++i)
		cin >> m[i];
	for (i = 1; i <= N; ++i)
		cq.push_back(i);

	for (i = 0; i < M; ++i) {
		for (j = 0; j < cq.size(); ++j) {
			if (cq[j] == m[i]) {
				idx = j;
				break;
			}
		}

		while (true) {
			if (cq.front() == m[i]) {
				cq.pop_front();
				break;
			}
			else if (idx < cq.size()-idx) {
				cq.push_back(cq.front());
				cq.pop_front();
				++cnt;
			}
			else {
				cq.push_front(cq.back());
				cq.pop_back();
				++cnt;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}