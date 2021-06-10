#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> min_heap;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, input;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> input;
		if (input == 0) {
			if (min_heap.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << min_heap.top() << '\n';
				min_heap.pop();
			}
		}
		else {
			min_heap.push(input);
		}
	}
	return 0;
}