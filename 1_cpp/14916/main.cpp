#include <iostream>
using namespace std;
int n, num5, num2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> n;

	// 처리
	num5 = n / 5;
	num2 = (n % 5) / 2;

	if (n % 5 % 2 == 1) {
		num2 += 3;
		num5 -= 1;
	}

	// 출력
	if (num5 == -1)
		cout << -1 << '\n';
	else
		cout << num2 + num5 << '\n';

	return 0;
}