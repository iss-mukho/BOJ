#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int xy[9][9];
	int i, j, max = 0, x=0, y=0;
	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
			cin >> xy[i][j];
			if (xy[i][j] > max) {
				max = xy[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << max << '\n' << x+1 << ' ' << y+1 << '\n';
	return 0;
}