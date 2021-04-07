#include <iostream>
#include <algorithm>
using namespace std;
int cup[3] = { 1,0,0 };
int main() {
	int M, i, x, y;
	cin >> M;
	for (i = 0; i < M; ++i) {
		cin >> x >> y;
		swap(cup[x - 1], cup[y - 1]);
	}
	x = -1;
	for (i = 0; i < 3; ++i)
		if (cup[i] == 1) {
			x = i+1;
			break;
		}
	cout << x << '\n';
	return 0;
}