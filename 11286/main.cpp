#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
// 절대값이 더 작은 값에 우선순위를 주고, 절대값이 같다면 더 작은 값에 우선순위를 높게 주는 비교함수
struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) {
			return true;
		}
		else if (abs(a) == abs(b)) {
			if(a > b)
				return true;
			else
				return false;
		}
		else {
			return false;
		}
	}
};
priority_queue<int, vector<int>, cmp> min_heap;
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