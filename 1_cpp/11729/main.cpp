#include <iostream>
#include <cmath>
using namespace std;
void hanoi(int n, int from, int to);
int main() {
	int N, count = 0;
	cin >> N;
	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(N, 1, 3);
	return 0;
}
void hanoi(int n, int from, int to) {
	if (n == 1)
		cout << from << ' ' << to << '\n';
	else {
		hanoi(n - 1, from, 6-(from+to));
		cout << from << ' ' << to << '\n';
		hanoi(n - 1, 6-(from+to), to);
	}
}