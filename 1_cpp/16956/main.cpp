// 백준 16956: 늑대와 양(실버 III), https://www.acmicpc.net/problem/16956
// AD Hoc.. 구성적?
#include <iostream>
#include <string>
using namespace std;

const int MAX = 500;
const int dx[4] = { -1, +1, +0, +0 };
const int dy[4] = { +0, +0, -1, +1 };

int R, C;
string inLine;
char pasture[MAX][MAX];
bool canInvade = false;

bool inRange(int x, int y) {
	if (0 <= x && x < R && 0 <= y && y < C)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cin >> inLine;
		for (int j = 0; j < C; ++j)
			pasture[i][j] = inLine[j];
	}

	// 처리
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (pasture[i][j] != 'S') continue;

			for (int d = 0; d < 4; ++d) {
				int ni = i + dx[d];
				int nj = j + dy[d];

				if (!inRange(ni, nj)) continue;
				if (pasture[ni][nj] == 'W') {
					canInvade = true;
					break;
				}

				if(pasture[ni][nj] == '.') pasture[ni][nj] = 'D';
			}
			if (canInvade) break;
		}
		if (canInvade) break;
	}

	// 출력
	if (canInvade)
		cout << 0 << '\n';
	else {
		cout << 1 << '\n';
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j)
				cout << pasture[i][j];
			cout << '\n';
		}
	}

	return 0;
}
