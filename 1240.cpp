/* 백준 1240: 노드사이의 거리(골드 V), https://www.acmicpc.net/problem/1240
* 트리: N-1개의 간선
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1000;

int N, M, s, e, w, dist;
vector<pii> graph[MAX+1];
bool visited[MAX+1];

int BFS(){
    fill_n(visited + 1, N, false); // 초기화
    deque<pii> dq;
    
    visited[s] = true;
    dq.push_back(pii(s, 0));

    while(!dq.empty()){
        int a = dq.front().first, c = dq.front().second;
        dq.pop_front();

        if(a == e) return c;

        for(auto &nxt: graph[a]){
            int b = nxt.first, d = nxt.second;
            if(visited[b]) continue;

            visited[b] = true;
            dq.push_back(pii(b, c + d));
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N-1; ++i){
        scanf("%d %d %d", &s, &e, &w);
        graph[s].push_back(pii(e, w));
        graph[e].push_back(pii(s, w));
    }

    for(int i=0; i<M; ++i){
        scanf("%d %d", &s, &e);
        printf("%d\n", BFS());
    }

    return 0;
}
