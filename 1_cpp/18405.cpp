// 백준 18405: 경쟁적 전염(골드 V), https://www.acmicpc.net/problem/18405
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 200;
const int dx[4] = {-1, +1, +0, +0};
const int dy[4] = {+0, +0, -1, +1};
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp; // (<time, num>, <x, y>)

int N, K, S, X, Y;
int graph[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {false, };

bool inRange(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < N)
        return true;
    return false;
}

void BFS(){
    priority_queue<ppp> pq;

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(graph[i][j] == 0) continue;
            if(visited[i][j]) continue;

            visited[i][j] = true;
            pq.push(ppp(pii(-0, -graph[i][j]), pii(i, j)));
        }
    }
    while(!pq.empty()){
        int curTime = -pq.top().first.first;
        int curNum = -pq.top().first.second;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();

        if(curTime == S) break;

        for(int d=0; d<4; ++d){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(!inRange(nx, ny)) continue;
            if(visited[nx][ny]) continue;
            if(graph[nx][ny] != 0) continue;

            visited[nx][ny] = true;
            graph[nx][ny] = curNum;
            pq.push(ppp(pii(-(curTime+1), -curNum), pii(nx, ny)));
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            scanf("%d", &graph[i][j]);
    scanf("%d %d %d", &S, &X, &Y);

    for(int i=0; i<S; ++i)
        BFS();

    printf("%d\n", graph[X-1][Y-1]);

    return 0;
}
