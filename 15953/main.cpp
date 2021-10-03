#include <iostream>
using namespace std;

int main() {
	int T, a, b, i;
	int aMoney, bMoney;

	cin >> T;

	for (i = 0; i < T; ++i) {
		cin >> a >> b;

		if (a == 0 or a >= 22) aMoney = 0;
		else if (a <= 1) aMoney = 5000000;
		else if (a <= 3) aMoney = 3000000;
		else if (a <= 6) aMoney = 2000000;
		else if (a <= 10) aMoney = 500000;
		else if (a <= 15) aMoney = 300000;
		else aMoney = 100000;

		if (b == 0 or b >= 32) bMoney = 0;
		else if (b <= 1) bMoney = 5120000;
		else if (b <= 3) bMoney = 2560000;
		else if (b <= 7) bMoney = 1280000;
		else if (b <= 15) bMoney = 640000;
		else bMoney = 320000;

		cout << aMoney + bMoney << '\n';
	}

	return 0;
}