// 백준 1865 웜홀(골드 III)
/**
 * 시작점이 없다 -> 벨만-포드 함수의 매개 변수 (int start) 제거
 *     - 따라서, 벨만-포드 알고리즘의 "시작점이 INF가 아니고"도 제거
 *     - 상단의 조건을 없애 주었을 때, 정답 처리를 받음
 */
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edgeType;
const int INF = 2100000000;
const int MAX = 500;
int TC, N, M, W, S, E, T;
vector<edgeType> edges;
int dist[MAX + 1];

void init() {
    fill_n(dist + 1, N, INF);
    edges.clear();
}
bool ballmanFord() {
    for (int i = 1; i <= N; ++i) {
        for (auto edge : edges) {
            S = edge.second.first, E = edge.second.second, T = edge.first;

            if (dist[E] > dist[S] + T) { // 시작점이 정해져 있지 않음
                dist[E] = dist[S] + T;
                if (i == N) return false;
            }
        }
    }
    return true;
}

int main() {
    // 입력
    scanf("%d", &TC);
    while (TC--) {
        init();
        scanf("%d %d %d", &N, &M, &W);

        // 단 도로는 방향이 없으며 웜홀은 방향이 있다.
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &S, &E, &T);
            edges.push_back(edgeType(T, pii(S, E)));
            edges.push_back(edgeType(T, pii(E, S)));
        }
        for (int i = 0; i < W; ++i) {
            scanf("%d %d %d", &S, &E, &T);
            edges.push_back(edgeType(-T, pii(S, E)));
        }

        // 처리 및 출력: 벨만-포드 알고리즘
        if (!ballmanFord()) printf("YES\n"); // 음수 사이클 존재 = 시간이 줄어들면서 시작점으로 돌아올 수 있음
        else printf("NO\n");
    }

    return 0;
}