/* ���� 14502: ������(��� IV), https://www.acmicpc.net/problem/14502
* �Ｚ SW ���� �׽�Ʈ A�� ���� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 8;

int N, M; // ����, ����
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

// lab �迭 �ʱ�ȭ
void init() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			lab[i][j] = LAB[i][j];
}

// visited �ʱ�ȭ
void visitedInit() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			visited[i][j] = false;
}

// ���� ������ ũ��
int getSafe() {
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (lab[i][j] == 0)
				++ans;
	return ans;
}

// ���̷��� �۶߸���
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

// 3���� �� ��ġ(DFS)
void setWall(int idx, int cnt) {
	if (cnt == 3) {
		init(); // lab �迭 �ʱ�ȭ
  		visitedInit(); // �湮 �迭 �ʱ�ȭ

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
	// �Է�
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &LAB[i][j]);
			if (LAB[i][j] == 0) empty_.push_back(pii(i, j));
			else if (LAB[i][j] == 2) virus.push_back(pii(i, j));
		}
	}

	// ó��
	init();
	emptyLen = empty_.size();
	for (int i = 0; i < emptyLen - 3; ++i)
		setWall(i, 0); // �� ��ġ -> BFS(���̷��� Ž��) -> ���� ���� Ȯ��

	// ���
	printf("%d\n", answer);

	return 0;
}