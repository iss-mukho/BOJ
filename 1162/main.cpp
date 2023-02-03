// 백준 1162: 도로포장(골드 I)
/**
* 첫 시도: 그런건 없어요~
* 힌트 1: 이차원 DP -> 답은 맞는데.. 1차 검정처럼 정답이 나오지 않음
* 힌트 2: cnt를 더 똑똑하게 관리하세요(https://excited-hyun.tistory.com/157)
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

			if (dist[e][cnt] > nw) { // 기존 다익스트라: 'nw' = e + w
				dist[e][cnt] = nw;
				pq.push(n(-nw, pii(e, cnt)));
			}
			if (cnt < K) { // 추가 포장이 가능한가
				if (dist[e][cnt + 1] > w) { // 'e' = nw - ew
					dist[e][cnt + 1] = w;
					pq.push(n(-w, pii(e, cnt + 1)));
				}
			}
		}
	}
}

int main() {
	// 입력
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(pli(c, b));
		graph[b].push_back(pli(c, a)); // 양방향
	}

	// 처리: 다익스트라
	for (int i = 1; i <= N; ++i)
		for (int k = 0; k <= K; ++k)
			dist[i][k] = INF;
	dijkstra(1);

	// 출력
	for (int k = 0; k <= K; ++k)
		answer = min(answer, dist[N][k]);
	printf("%lld\n", answer);

	return 0;
}
