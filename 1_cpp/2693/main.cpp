#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A(10);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, i, j, input;
	cin >> N;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < 10; ++j) {
			cin >> input;
			A.push_back(input);
		}

		sort(A.begin(), A.end(), greater<int>());
		cout << A[2] << '\n';
		A.clear();
	}

	return 0;
}