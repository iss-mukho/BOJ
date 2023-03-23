#include <iostream>
using namespace std;

int hansu(int x);
int main() {
	int X;
	cin >> X;
	cout << hansu(X) << '\n';
	return 0;
}
int hansu(int x) {
	if (x < 100)
		return x;
	else {
		int cnt = 99;
		if (x == 1000)
			cnt--;
		
		for (int i = 100; i <= x; i++) {
			int a = (i % 1000 / 100) - (i % 100 / 10);
			int b = (i % 100 / 10) - (i % 10);
			if (a == b)
				cnt++;
		}
		return cnt;
	}
}
