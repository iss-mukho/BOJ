#include <iostream>
using namespace std;
int main() {
	int i, out, in, p = 0, max = -1;
	for (i = 0; i < 4; ++i) {
		cin >> out >> in;
		p = p - out + in;
		if (p > max)
			max = p;
	}
	cout << max << '\n';
	return 0;
}