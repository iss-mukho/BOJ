/** Version 2: 다익스트라 응용 알고리즘
 * 백준 5719: 거의 최단 경로(플래티넘 5)
 * 양방향 그래프 아님, 최대 10000000
 * - 어떻게 경로를 저장할 것인가?
 * - 다익스트라 알고리즘을 어떻게 변형 할 것인가?
 *
 * 힌트
 * 1. 다익스트라 알고리즘을 1회 실행 + 경로값 저장
 * 2. BFS를 통해 도착점 -> 시작점으로 경로를 제거해주고, 다익스트라 알고리즘을 1회 실행
 * - 고려: 최단 거리를 가지는 경로가 여러 개일 수도 있다.
 * - 경로:
 * Thanks to: https://kimtaehyun98.tistory.com/86
 * Thanks to: https://kibbomi.tistory.com/192
 */
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 500;
const int INF = 10000000; // M*P = 10000 * 1000

int N, M, S, D, U, V, P;
vector<pii> graph[MAX]; // (end, weight)
int dist[MAX];
priority_queue<pii> pq; // 다익스트라용, (-weight, end)
vector<int> path[MAX]; // 경로, (start, end)
bool visited[MAX]; // 최단 경로-제거 확인용
queue<int> q; // BFS용

void dijkstra(int start) {
    dist[start] = 0;
    pq.push(pii(0, start));

    while (!pq.empty()) {
        int s = pq.top().second, w = -pq.top().first;
        pq.pop();

        if (dist[s] < w) continue;
        for (auto n : graph[s]) {
            int e = n.first, ew = n.second;
            if (ew == -1) continue; // 두번째 거르기

            int nw = w + ew;
            if (dist[e] > nw) {
                dist[e] = nw; // 거리 갱신
                pq.push(pii(-nw, e));

                path[e].clear(); // 최단 경로에 포함된 간선 모두 제거
                path[e].push_back(s); // 경로 갱신
            }
            else if (dist[e] == nw) path[e].push_back(s); // 거리가 같다면 그냥 경로 추가
        }
    }
}

// 끝 지점부터 시작 지점까지의 경로를 제거
void bfs(int end) {
    q.push(end);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        if (visited[s]) continue; // 제거한 간선은 건너뛴다
        visited[s] = true;
        for (auto b : path[s]) { // e -> s: before
            for (int i = 0; i < graph[b].size(); ++i) {
                // 여기서 for(auto g: graph[b]) { if(g.first == s) ... } 꼴로 사용하면 값 갱신이 되지 않는다.
                if (graph[b][i].first == s)
                    graph[b][i].second = -1; // 간선 삭제
            }
            q.push(b);
        }
    }
}

int main() {
    while (1) {
        // 입력 1
        scanf("%d %d", &N, &M);
        if (N == 0) break; // 종료 조건

        // dist 초기화
        fill_n(dist, N, INF);

        // 입력2
        scanf("%d %d", &S, &D);

        // 입력3
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &U, &V, &P);
            graph[U].push_back(pii(V, P));
        }

        // 다익스트라 알고리즘
        dijkstra(S);

        // 최단 거리 간선 정보 제거
        bfs(D); // end부터 start까지 연결된 간선들 제거

        // 초기화 및 다익스트라 알고리즘 재수행
        fill_n(dist, N, INF);
        dijkstra(S);

        // 출력
        if (dist[D] == INF)
            printf("%d\n", -1);
        else
            printf("%d\n", dist[D]);

        // 초기화
        fill_n(dist, N, INF);
        for (int i = 0; i < N; ++i) graph[i].clear();
        for (int i = 0; i < N; ++i) path[i].clear();
        fill_n(visited, N, false);
    }

    return 0;
}
