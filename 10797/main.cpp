#include <iostream>
using namespace std;
int main() {
	int N, i, input, cnt = 0;
	cin >> N;
	for (i = 0; i < 5; ++i) {
		cin >> input;
		if (N == input)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}