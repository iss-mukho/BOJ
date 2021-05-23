#include <iostream>
using namespace std;
int main() {
	int input[5];
	int i, sum = 0;
	for (i = 0; i < 5; ++i) {
		cin >> input[i];
		sum += input[i] * input[i];
	}
	cout << sum % 10 << '\n';
	return 0;
}