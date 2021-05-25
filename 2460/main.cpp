#include <iostream>
using namespace std;
int main() {
	int i, out, in, p = 0, max = -1;
	for (i = 0; i < 10; ++i) {
		cin >> out >> in;
		p = p - out;
		if (p > max)
			max = p;
		p = p + in;
		if (p > max)
			max = p;
	}
	cout << max << '\n';
	return 0;
}