// 백준 1719, 택배(골드 III): https://www.acmicpc.net/problem/1719
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 10000000;
const int MAX = 200;
int graph[MAX + 1][MAX + 1];
int before[MAX + 1][MAX + 1];
int n, m, a, b, c;

int main() {
	// 입력 1
	scanf("%d %d", &n, &m);

	// 초기화
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			graph[i][j] = INF;
		}
	}

	// 입력 2
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;

		// 직후 경로 갱신
		before[a][b] = b;
		before[b][a] = a;
	}

	// 플로이드 워셜
	for (int m = 1; m <= n; ++m) {
		for (int s = 1; s <= n; ++s) {
			for (int e = 1; e <= n; ++e) {
				if (graph[s][e] > graph[s][m] + graph[m][e]) {
					graph[s][e] = graph[s][m] + graph[m][e];
					before[s][e] = before[s][m]; // '직후 경로'를 받아옴
				}
			}
		}
	}
	
	// 출력
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) printf("- ");
			else printf("%d ", before[i][j]);
		}
		printf("\n");
	}

	return 0;
}