#include <iostream>
#include <algorithm>
using namespace std;
int input[100000] = {0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, i, j, a, cnt = 0;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> input[i];
	cin >> x;
	sort(input, input + n);
	i = 0; j = n - 1;
	while (i < j) {
		a = input[i] + input[j];
		if (a == x) {
			++cnt;
			++i, --j;
		}
		else if (a < x)
			++i;
		else
			--j;
	}
	cout << cnt << '\n';
	return 0;
}