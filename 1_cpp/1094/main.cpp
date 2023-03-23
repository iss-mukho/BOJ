#include <iostream>
using namespace std;
int main() {
	int X, a = 64, temp = 0, cnt = 0;
	cin >> X;
	while (a >= 1) {
		if (X >= a+temp) {
			temp += a;
			++cnt;
		}
		a /= 2;
		if (X == temp)
			break;
	}
	cout << cnt << '\n';
	return 0;
}