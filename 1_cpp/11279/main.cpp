#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> max_heap;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, input;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> input;
		if (input == 0) {
			if (max_heap.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << max_heap.top() << '\n';
				max_heap.pop();
			}
		}
		else {
			max_heap.push(input);
		}
	}
	return 0;
}