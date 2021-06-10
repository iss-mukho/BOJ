#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;
int main() {
	// max(-3, -2, -1, 0) min(1, 2, 3)
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i, mid, input, temp1, temp2;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> input;
		if (i%2 == 0)
			maxpq.push(input);
		else
			minpq.push(input);
		if (i > 0) {
			if (minpq.top() < maxpq.top()) {
				temp1 = maxpq.top();
				temp2 = minpq.top();
				maxpq.pop(); minpq.pop();
				maxpq.push(temp2); minpq.push(temp1);
			}
		}
		cout << maxpq.top() << '\n';
	}
	return 0;
}