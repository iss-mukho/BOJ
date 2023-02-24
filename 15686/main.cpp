// 백준 15686: 치킨 배달(골드 V), https://www.acmicpc.net/problem/15686
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 50, cMAX = 13, INF = 2100000000;

int N, M, graph[MAX][MAX], answer = INF;
vector<pii> home, chick, selectedChick;
bool visited[cMAX];

// 선택된 치킨집과 각 집 간의 최단 거리를 구하는 함수
int calc() {
	int ans = 0;
	for (auto h : home) {
		int hx = h.first, hy = h.second, dist = INF;

		for (auto s : selectedChick) {
			int sx = s.first, sy = s.second, tempDist = abs(sx-hx) + abs(sy-hy);
			dist = min(dist, tempDist);
		}
		ans += dist;
	}
	return ans;
}

// 치킨집의 M개 조합을 구해 계산
void selectChick(int idx, int cnt) {
	if (cnt == M) {
		answer = min(answer, calc());
		return;
	}

	for (int i = idx; i < chick.size(); ++i) {
		if (visited[i]) continue;

		visited[i] = true;
		selectedChick.push_back(chick[i]);
		selectChick(i, cnt + 1);
		selectedChick.pop_back();
		visited[i] = false;
	}
}

int main() {
	// 입력
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &graph[i][j]);

			if (!graph[i][j]) continue;
			if (graph[i][j] == 1) home.push_back(pii(i, j));
			else chick.push_back(pii(i, j));
		}
	}

	// 처리: Brute Force
	selectChick(0, 0);

	// 출력
	printf("%d\n", answer);

	return 0;
}