#include <iostream>
using namespace std;
int input[50];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, min = 1000001, max = 0;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> input[i];
		if (input[i] < min)
			min = input[i];
		if (input[i] > max)
			max = input[i];
	}
	cout << max * min << '\n';;
	return 0;
}