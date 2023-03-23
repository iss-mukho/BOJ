// 백준 1005: ACM Craft(골드 III)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

const int MAX = 1000;
int T, N, K, D, X, Y, W;
vector<int> build[MAX + 1];
int buildTime[MAX + 1];
int curMax[MAX + 1]; // indegree가 0이 되기 전의 최대 시간 정보
int indegree[MAX + 1];

void init() {
	for (int i = 1; i <= N; ++i) build[i].clear();
	fill_n(buildTime + 1, N, 0);
	fill_n(curMax + 1, N, 0);
	fill_n(indegree + 1, N, 0);
}
void topologySort() {
	deque<int> dq;

	for (int i = 1; i <= N; ++i)
		if (indegree[i] == 0)
			dq.push_back(i);

	while (!dq.empty()) {
		int s = dq.front();
		dq.pop_front();

		for (auto e : build[s]) {
			if (--indegree[e] == 0) {
				dq.push_back(e);
				buildTime[e] += max(curMax[e], buildTime[s]);
			}
			else curMax[e] = max(curMax[e], buildTime[s]); // indegree가 0이 아닐 때, 최대 시간 정보 갱신
		}
	}
}

int main() {
	// 입력: 테스트케이스의 개수
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &K); // 입력: 건물의 개수와 건설순서 규칙 개수

		 // 입력: 건설 시간
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &D);
			buildTime[i] = D;
		}

		// 입력: 건설 순서
		for (int i = 0; i < K; ++i) {
			scanf("%d %d", &X, &Y);
			build[X].push_back(Y);
			++indegree[Y];
		}

		// 입력: 건물의 번호
		scanf("%d", &W);

		// 처리: 위상 정렬
		topologySort();

		// 출력
		printf("%d\n", buildTime[W]);

		// 초기화
		init();
	}

	return 0;
}