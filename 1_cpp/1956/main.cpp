// ���� 1956: �(��� IV)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
const int MAX = 400;
int V, E, a, b, c, answer = INF;
int graph[MAX + 1][MAX + 1];

int main() {
	// �Է� 1
	scanf("%d %d", &V, &E);

	// �ʱ�ȭ
	for (int i = 1; i <= V; ++i)
		for (int j = 1; j <= V; ++j)
			graph[i][j] = INF;
	
	// �Է� 2
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}

	// ó��: �÷��̵� ����
	for (int m = 1; m <= V; ++m)
		for (int s = 1; s <= V; ++s)
			for (int e = 1; e <= V; ++e)
				graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e]);
	
	// ���
	for (int i = 1; i <= V; ++i) answer = min(answer, graph[i][i]);
	if (answer == INF) printf("%d\n", -1);
	else printf("%d\n", answer);

	return 0;
}