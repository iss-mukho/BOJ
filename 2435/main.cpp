#include <iostream>
using namespace std;
int input[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, i, j, temp = 0, max_;
	cin >> N >> K;
	for (i = 0; i < N; ++i)
		cin >> input[i];

	for (i = 0; i < K; ++i)
		temp += input[i];
	max_ = temp;

	for (i = K; i < N; ++i) {
		temp = temp - input[i - K] + input[i];

		if (max_ < temp)
			max_ = temp;
	}
	
	cout << max_ << '\n';

	return 0;
}