#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> min_heap;
int main() {
	int n, m, i;
	long long temp, sum = 0;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		cin >> temp;
		min_heap.push(temp);
	}
	for (i = 0; i < m; ++i) {
		temp = min_heap.top();
		min_heap.pop();
		temp += min_heap.top();
		min_heap.pop();
		min_heap.push(temp);
		min_heap.push(temp);
	}
	while (!min_heap.empty()) {
		sum += min_heap.top();
		min_heap.pop();
	}
	cout << sum << '\n';
	return 0;
}