/** Version 1: 다익스트라 기본 알고리즘
 * 백준 5719: 거의 최단 경로(플래티넘 5)
 * 양방향 그래프 아님, 최대 10000000 
 * - 어떻게 경로를 저장할 것인가?
 * - 다익스트라 알고리즘을 어떻게 변형 할 것인가?
 * 
 * 힌트
 * 1. 다익스트라 알고리즘을 1회 실행 + 경로값 저장
 * 2. BFS를 통해 도착점 -> 시작점으로 경로를 제거해주고, 다익스트라 알고리즘을 1회 실행
 * - 고려: 최단 거리를 가지는 경로가 여러 개일 수도 있다.
 */
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
priority_queue<pii> pq; // (-weight, end)

void dijkstra(int start){
    dist[start] = 0;
    pq.push(pii(0, start));

    while(!pq.empty()){
        int s = pq.top().second, w = -pq.top().first;
        pq.pop();

        if(dist[s] < w) continue;
        for(auto n: graph[s]){
            int e = n.first, ew = n.second + w;
            if(dist[e] > ew){
                dist[e] = ew;
                pq.push(pii(-ew, e));
            }
        }
    }
}

int main(){
    while(1){
        // 입력 1
        scanf("%d %d", &N, &M);
        if(N == 0) break; // 종료 조건

        // dist 초기화
        fill_n(dist, N, INF);

        // 입력2
        scanf("%d %d", &S, &D);

        // 입력3
        for(int i=0; i<M; ++i){
            scanf("%d %d %d", &U, &V, &P);
            graph[U].push_back(pii(V, P));
        }

        // 다익스트라 알고리즘
        dijkstra(S);

        // 출력
        if(dist[D] == INF)
            printf("%d\n", -1);
        else
            printf("%d\n", dist[D]);
    }

    return 0;
}
