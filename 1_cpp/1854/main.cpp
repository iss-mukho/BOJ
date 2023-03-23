// Thanks to: https://goodbyeanma.tistory.com/66
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1000;
vector<pii> graph[MAX];
priority_queue<int> kthQueue[MAX];
int n, m, k, a, b, c;

// ��θ� ��� ���ؼ� kthQueue�� ����
// k���� �Ѿ kthQueue�� ������ �� top�� ������ �۴ٸ� pop �� ����
void dijkstra() {
	priority_queue <pii> pq;
	pq.push(pii(-0, 0));
	kthQueue[0].push(0);

	while (!pq.empty()) {
		int s = pq.top().second, w = -pq.top().first;
		pq.pop();

		for (auto n : graph[s]) {
			int e = n.first, nw = w + n.second;

			if (kthQueue[e].size() < k) {
				kthQueue[e].push(nw);
				pq.push(pii(-nw, e));
			}
			else if (kthQueue[e].top() > nw) {
				kthQueue[e].pop();
				kthQueue[e].push(nw);
				pq.push(pii(-nw, e));
			}
		}
	}
}

int main() {
	// �Է�
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a - 1].push_back(pii(b - 1, c));
	}

	// ó��
	dijkstra();

	// ���
	for (int i = 0; i < n; ++i) {
		if (kthQueue[i].size() != k) printf("%d\n", -1);
		else printf("%d\n", kthQueue[i].top());
	}
	printf("\n");

	return 0;
}