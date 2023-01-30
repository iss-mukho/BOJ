// ���� 1719, �ù�(��� III): https://www.acmicpc.net/problem/1719
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
	// �Է� 1
	scanf("%d %d", &n, &m);

	// �ʱ�ȭ
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			graph[i][j] = INF;
		}
	}

	// �Է� 2
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;

		// ���� ��� ����
		before[a][b] = b;
		before[b][a] = a;
	}

	// �÷��̵� ����
	for (int m = 1; m <= n; ++m) {
		for (int s = 1; s <= n; ++s) {
			for (int e = 1; e <= n; ++e) {
				if (graph[s][e] > graph[s][m] + graph[m][e]) {
					graph[s][e] = graph[s][m] + graph[m][e];
					before[s][e] = before[s][m]; // '���� ���'�� �޾ƿ�
				}
			}
		}
	}
	
	// ���
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) printf("- ");
			else printf("%d ", before[i][j]);
		}
		printf("\n");
	}

	return 0;
}