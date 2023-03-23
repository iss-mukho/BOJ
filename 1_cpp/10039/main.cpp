#include <iostream>
using namespace std;
int main() {
	int i, input, sum = 0;
	for (i = 0; i < 5; ++i) {
		cin >> input;
		if (input < 40)
			input = 40;
		sum += input;
	}
	cout << sum / 5 << '\n';
	return 0;
}