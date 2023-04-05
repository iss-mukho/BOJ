// 백준 8545: Zadanie próbne(브론즈 V), https://www.acmicpc.net/problem/8545
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	cout << str << '\n';

	return 0;
}
