// ���� 2665: �̷θ����(�� IV), https://www.acmicpc.net/problem/2665
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <deque>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 50;
const int INF = 999999999;

int N, graph[MAX][MAX], visited[MAX][MAX];
char oneLine[MAX + 1];

// U, D, L, R
int dx[4] = { +0, +0, -1, +1 };
int dy[4] = { -1, +1, +0, +0 };
bool inRange(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < N)
		return true;
	return false;
}

void BFS(pii start) {
	deque<pii> dq;
	dq.push_back(start);
	visited[start.first][start.second] = 0;

	while (!dq.empty()) {
		int cx = dq.front().first, cy = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (!inRange(nx, ny)) continue;

			if (graph[nx][ny] == 1) { // ����� ���� ��ü���� �ʰ� �̵�
				if (visited[nx][ny] <= visited[cx][cy]) continue;
				
				visited[nx][ny] = visited[cx][cy];
				dq.push_back(pii(nx, ny));
			}
			else{ // �������� ���� ��ü�ϸ鼭 �̵�
				if (visited[nx][ny] <= visited[cx][cy] + 1) continue; 
				
				visited[nx][ny] = visited[cx][cy] + 1;
				dq.push_back(pii(nx, ny));
			}
		}
	}
}

int main() {
	// �Է�
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%s", &oneLine);
		for (int j = 0; j < N; ++j)
			graph[i][j] = oneLine[j] - '0';
	}

	// �ʱ�ȭ
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			visited[i][j] = INF;

	// ó��
	BFS(pii(0, 0));

	// ���
	printf("%d\n", visited[N - 1][N - 1]);

	return 0;
}