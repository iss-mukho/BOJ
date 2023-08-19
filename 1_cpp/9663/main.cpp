#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 15;

int rows[MAX];
int N, answer = 0;

bool check(int curRow) {
	for (int r = curRow - 1; r > -1; --r)
		if (rows[curRow] == rows[r]
			|| (curRow - rows[curRow]) == (r - rows[r])
			|| (curRow + rows[curRow]) == (r + rows[r]))
			return false;
	return true;
}

void dfs(int row) {
	if (row == N) {
		++answer;
		return;
	}

	for (int c = 0; c < N; ++c) {
		rows[row] = c;
		if (check(row)) dfs(row + 1);
		rows[row] = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		fill_n(rows, N, -1);

	for (int c = 0; c < N; ++c) {
		rows[0] = c;
		dfs(1);
	}
		
	cout << answer;

	return 0;
}