// 백준 2206: 벽 부수고 이동하기(골드 III)
/**
* 첫 시도: 시간 초과
*	- 완전 탐색을 시도했으나 실패
* 두 번째 시도: 3차원 배열
*	- 벽을 안부쉈을 때, 부쉈을 때를 구분하여 O(1)로 진행
*	- 'n -> n', 'n -> b', 'b -> n'에 대해서 구분(like DP)
*	-> 맞았습니다!!
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1000001;
const int MAX = 1000;

int graph[MAX + 1][MAX + 1];
int cnt[MAX + 1][MAX + 1][2];
int N, M, answer = INF;
char inLine[MAX + 5];
vector<pii> block;
deque<pii> dq;

// U, D, L, R
int dx[4] = { +0, +0, -1, +1 };
int dy[4] = { -1, +1, +0, +0 };
bool inRange(int x, int y) {
	if (1 <= x && x <= N && 1 <= y && y <= M) return true;
	return false;
}

void BFS(int x, int y) {
	dq.push_back(pii(x, y));
	cnt[x][y][0] = 1;

	while (!dq.empty()) {
		int cx = dq.front().first, cy = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (!inRange(nx, ny)) continue;

			if(graph[nx][ny] == 0) {
				if (cnt[nx][ny][0] > cnt[cx][cy][0] + 1) { // N -> N
					cnt[nx][ny][0] = cnt[cx][cy][0] + 1;
					dq.push_back(pii(nx, ny));
				}
				if (cnt[nx][ny][1] > cnt[cx][cy][1] + 1) { // N -> B
					cnt[nx][ny][1] = cnt[cx][cy][1] + 1;
					dq.push_back(pii(nx, ny));
				}
			}
			else {
				if (cnt[nx][ny][1] > cnt[cx][cy][0] + 1) { // B -> N
					cnt[nx][ny][1] = cnt[cx][cy][0] + 1;
					dq.push_back(pii(nx, ny));
				}
			}
		}
	}

	answer = min(answer, min(cnt[N][M][0], cnt[N][M][1]));
}

int main() {
	// 입력
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		scanf("%s", &inLine);
		for (int j = 1; j <= M; ++j) {
			graph[i][j] = inLine[j - 1] - '0';
			if (inLine[j - 1] == '1') block.push_back(pii(i, j));
		}
	}

	// 처리
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cnt[i][j][0] = INF;
			cnt[i][j][1] = INF;
		}
	}
	BFS(1, 1);

	// 출력
	if (answer == INF) printf("%d\n", -1);
	else printf("%d\n", answer);

	return 0;
}