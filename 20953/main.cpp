#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, a, b, i;
	cin >> T;
	for (i = 0; i < T; ++i) {
		cin >> a >> b;
		int output = (pow(a + b, 2) * (a + b - 1)) / 2;
		cout << output << '\n';
	}

	return 0;
}