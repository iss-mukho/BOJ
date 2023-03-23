#include <iostream>
using namespace std;
int store[9] = {};
bool isDone[9] = { false, };
void backtracking(int cnt, int n, int m);
int main() {
	int N, M;
	cin >> N >> M;
	backtracking(0, N, M);
	return 0;
}
void backtracking(int cnt, int n, int m) {
	if (cnt == m) {
		for (int i = 0;i < m;i++)
			cout << store[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1;i <= n;i++) {
		if (!isDone[i]) {
			for(int j=0;j<i;j++)
				isDone[j] = true;
			store[cnt] = i;
			backtracking(cnt + 1, n, m);
			for (int j = 0;j < i;j++)
				isDone[j] = false;
		}
	}
}