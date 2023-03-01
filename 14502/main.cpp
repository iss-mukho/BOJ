/* 백준 14502: 연구소(골드 IV), https://www.acmicpc.net/problem/14502
* 삼성 SW 역량 테스트 A형 기출 문제
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 8;

int N, M; // 세로, 가로
int LAB[MAX][MAX], lab[MAX][MAX], emptyLen = -1, answer = 0;
bool visited[MAX][MAX], walled[MAX*MAX];
vector<pii> empty_;
vector<pii> virus;

// U, D, L, D
const int dx[4] = { +0, +0, -1, +1 };
const int dy[4] = { -1, +1, +0, +0 };
bool inRange(int x, int y) {
	if (0 <= x && x < N && 0 <= y  && y< M)
		return true;
	return false;
}

// lab 배열 초기화
void init() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			lab[i][j] = LAB[i][j];
}

// visited 초기화
void visitedInit() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			visited[i][j] = false;
}

// 안전 영역의 크기
int getSafe() {
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (lab[i][j] == 0)
				++ans;
	return ans;
}

// 바이러스 퍼뜨리기
void BFS(pii start) {
	deque<pii> dq;
	dq.push_back(start);
	visited[start.first][start.second] = true;

	while (!dq.empty()) {
		int cx = dq.front().first, cy = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			
			if (!inRange(nx, ny)) continue;
			if (visited[nx][ny]) continue;
			if (lab[nx][ny] > 0) continue;

			lab[nx][ny] = 2;
			visited[nx][ny] = true;
			dq.push_back(pii(nx, ny));
		}
	}
}

// 3개의 벽 설치(DFS)
void setWall(int idx, int cnt) {
	if (cnt == 3) {
		init(); // lab 배열 초기화
  		visitedInit(); // 방문 배열 초기화

		for (auto &v: virus) {
			int vx = v.first, vy = v.second;
			if (!visited[vx][vy] && lab[vx][vy] == 2)
				BFS(pii(vx, vy));
		}
				
		answer = max(answer, getSafe());
		return;
	}

	for (int i = idx; i < emptyLen; ++i) {
		int wx = empty_[i].first, wy = empty_[i].second;
		LAB[wx][wy] = 1;
		setWall(i + 1, cnt + 1);
		LAB[wx][wy] = 0;
	}
}

int main() {
	// 입력
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &LAB[i][j]);
			if (LAB[i][j] == 0) empty_.push_back(pii(i, j));
			else if (LAB[i][j] == 2) virus.push_back(pii(i, j));
		}
	}

	// 처리
	init();
	emptyLen = empty_.size();
	for (int i = 0; i < emptyLen - 3; ++i)
		setWall(i, 0); // 벽 설치 -> BFS(바이러스 탐색) -> 안전 구역 확인

	// 출력
	printf("%d\n", answer);

	return 0;
}