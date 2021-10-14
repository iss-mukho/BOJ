#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, i, input, output = 200000;
	cin >> N;
	for (i = 0; i < 2 * N; ++i) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	for (i = 0; i < N; ++i) {
		input = v[i] + v[2 * N - 1 - i];
		if (output > input)
			output = input;
	}
	cout << output << '\n';
	return 0;
}