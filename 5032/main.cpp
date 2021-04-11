#include <iostream>
using namespace std;
int main() {
	int e, f, c, temp, sum = 0;
	cin >> e >> f >> c;
	temp = e + f;
	while (1) {
		if (temp < c)
			break;
		sum += temp / c;
		temp = (temp % c) + (temp / c);
	}
	cout << sum << '\n';
	return 0;
}