// 백준 15727: 조별과제를 하려는데 조장이 사라졌다(브론즈 V), https://www.acmicpc.net/problem/15727
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float n;
	cin >> n;
	cout << ceil(n / 5) << '\n';
	return 0;
}
