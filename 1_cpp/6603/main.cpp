#include <iostream>
#include <vector>
using namespace std;
int input[13];
bool isSearch[13] = { false, };
int store[6] = {};
void backtracking(int cnt, int n);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, i;
	while (true) {
		cin >> k;
		if (k == 0)
			break;
		for (i = 0; i < k; ++i)
			cin >> input[i];
		backtracking(0, k);
		cout << '\n';
	}
	return 0;
}
void backtracking(int cnt, int n) {
	if (cnt == 6) {
		for (int i = 0; i < 6; ++i)
			cout << store[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!isSearch[i]) {
			for (int j = 0; j <= i; ++j)
				isSearch[j] = true;
			store[cnt] = input[i];
			backtracking(cnt + 1, n);
			for (int j = 0; j <= i; ++j)
				isSearch[j] = false;
		}
	}
}