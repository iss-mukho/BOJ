#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, dasom, i, temp, maesu = 0;
	cin >> N;
	cin >> dasom;
	for (i = 1; i < N; ++i) {
		cin >> temp;
		pq.push(temp);
	}
	while (pq.size()>0) {
		if (dasom > pq.top())
			break;
		temp = pq.top();
		pq.pop();
		pq.push(--temp);
		++dasom;
		++maesu;
	}
	cout << maesu << '\n';
	return 0;
}