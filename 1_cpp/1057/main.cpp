#include <iostream>
using namespace std;
int getRound(int n) {
	return n % 2 == 0 ? n / 2 : n / 2 + 1;
}
int main() {
	int N, k, l, R = 1;
	cin >> N >> k >> l;
	while (N) {
		if (getRound(k) == getRound(l))
			break;
		k = getRound(k);
		l = getRound(l);
		++R;
		N /= 2;
	}
	cout << R << '\n';
	return 0;
}