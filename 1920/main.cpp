#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binary_search(int low, int high, int key);
vector<int> input;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, i, num;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> num;
		input.push_back(num);
	}
	sort(input.begin(), input.end());
	cin >> M;
	for (i = 0; i < M; ++i) {
		cin >> num;
		cout << binary_search(0, N - 1, num) << '\n';
	}
	return 0;
}
int binary_search(int low, int high, int key) {
	int mid;
	if (low > high)
		return 0;
	else {
		mid = (low + high) / 2;
		if (input[mid] == key)
			return 1;
		else if (input[mid] > key)
			return binary_search(low, mid - 1, key);
		else
			return binary_search(mid + 1, high, key);
	}
}