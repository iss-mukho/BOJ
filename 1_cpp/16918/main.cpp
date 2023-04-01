// 백준 16918: 봄버맨, https://www.acmicpc.net/problem/16918
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 200;
const int dx[4] = { -1, +1, +0, +0 };
const int dy[4] = { +0, +0, -1, +1 };

int R, C, N, currentTime = 2;
int setBoomTime[MAX][MAX];
char inLine[MAX + 1];

bool inRange(int x, int y) {
	if (0 <= x && x < R && 0 <= y && y < C)
		return true;
	return false;
}

int main() {
	int _ = scanf("%d %d %d", &R, &C, &N);

	for (int i = 0; i < R; ++i) {
		fill_n(setBoomTime[i], C, -1);

		_ = scanf("%s", &inLine);
		for (int j = 0; j < C; ++j)
			if (inLine[j] == 'O') setBoomTime[i][j] = 0; // 0초
	}
	
	// 2초부터
	while (currentTime <= N) {
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (currentTime % 2 == 0) {                 
					if (setBoomTime[i][j] > -1) continue;
					setBoomTime[i][j] = currentTime;
				}
				else { // 4번
					// 설치한지 3초가 지난 폭탄과 인접한 폭탄을 터뜨림
					if (setBoomTime[i][j] != currentTime-3) continue;

					setBoomTime[i][j] = -1;
					for (int k = 0; k < 4; ++k) {
						int nx = i + dx[k], ny = j + dy[k];

						if (!inRange(nx, ny)) continue;
						if (setBoomTime[nx][ny] == currentTime - 3) continue; // 조건에 맞는 폭탄은 동시에 폭발함
						setBoomTime[nx][ny] = -1;
					}
				}
			}
		}

		++currentTime;
	}
		
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (setBoomTime[i][j] == -1) printf("%c", '.');
			else printf("%c", 'O');
		}
		printf("\n");
	}
	
	return 0;
}
