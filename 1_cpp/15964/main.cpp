// 백준 15964: 이상한 기호(브론즈 V), https://www.acmicpc.net/problem/15964
#include <iostream>
using namespace std;

long long calc(long long a, long long b) {
	return (a + b) * (a - b);
}

int main() {
	long long A, B;
	cin >> A >> B;
	cout << calc(A, B) << '\n';
	return 0;
}
