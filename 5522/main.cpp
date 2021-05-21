#include <iostream>
using namespace std;
int main() {
	int num, sum = 0, i;
	for (i = 0; i < 5; ++i) {
		cin >> num;
		sum += num;
	}
	cout << sum << '\n';
	return 0;
}