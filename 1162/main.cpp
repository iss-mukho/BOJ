// ���� 1162: ��������(��� I)
/**
* ù �õ�: �׷��� �����~
* ��Ʈ 1: ������ DP -> ���� �´µ�.. 1�� ����ó�� ������ ������ ����
* ��Ʈ 2: cnt�� �� �ȶ��ϰ� �����ϼ���(https://excited-hyun.tistory.com/157)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<ll, pii> n;
const ll INF = 50000000001;
const int MAX = 10000;
ll dist[MAX + 1][20 + 1]; // DP
int N, M, K, a, b, c, cnt = 0;
ll answer = INF;
vector<pli> graph[MAX + 1]; // (c, b)
priority_queue<n> pq; // (-c, (b, k))

void dijkstra(int start) {
	dist[start][0] = 0;
	pq.push(n(-0, pii(start, 0)));

	while (!pq.empty()) {
		int s = pq.top().second.first;
		ll w = -pq.top().first;
		int cnt = pq.top().second.second;
		pq.pop();

		if (dist[s][cnt] < w) continue;
		
		for (int i = 0; i < graph[s].size(); ++i) {
			int e = graph[s][i].second;
			ll ew = graph[s][i].first;

			ll nw = w + ew;

			if (dist[e][cnt] > nw) { // ���� ���ͽ�Ʈ��: 'nw' = e + w
				dist[e][cnt] = nw;
				pq.push(n(-nw, pii(e, cnt)));
			}
			if (cnt < K) { // �߰� ������ �����Ѱ�
				if (dist[e][cnt + 1] == INF || dist[e][cnt + 1] > w) { // 'e' = nw - ew
					dist[e][cnt + 1] = w;
					pq.push(n(-w, pii(e, cnt + 1)));
				}
			}
		}
	}
}

int main() {
	// �Է�
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(pli(c, b));
		graph[b].push_back(pli(c, a)); // �����
	}

	// ó��: ���ͽ�Ʈ��
	for (int i = 1; i <= N; ++i)
		for (int k = 0; k <= K; ++k)
			dist[i][k] = INF;
	dijkstra(1);

	// ���
	for (int k = 0; k <= K; ++k)
		answer = min(answer, dist[N][k]);
	printf("%lld\n", answer);

	return 0;
}