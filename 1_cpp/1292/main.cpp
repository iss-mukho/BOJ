#include <iostream>
using namespace std;
int main() {
	int N[1000];
	int A, B, i, j, cnt = 1, sum = 0;
	cin >> A >> B;
	for (i = 0; i < 1000;) {
		for (j = 0; j < cnt; ++j)
			if(i<1000)
				N[i++] = cnt;
		++cnt;
	}
	for (i = A - 1; i < B; ++i)
		sum += N[i];
	cout << sum << '\n';
	return 0;
}