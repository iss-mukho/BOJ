#include <iostream>
#include <cmath>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T, a, b, i, base;
	cin >> T;
	for (i = 0; i < T; ++i) {
		cin >> a >> b;
		base = a % 10;
		if (base == 0)
			cout << 10 << '\n';
		else if (base == 1 || base == 5 || base == 6)
			cout << base << '\n';
		else if (base == 4 || base == 9) {
			if (b % 2 == 0)
				cout << int(pow(base, 2)) % 10 << '\n';
			else
				cout << base << '\n';
		}
		else {
			if (b % 4 == 0)
				cout << int(pow(base, 4)) % 10 << '\n';
			else
				cout << int(pow(base, b % 4)) % 10 << '\n';
		}
	}
	return 0;
}