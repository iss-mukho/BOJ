// 백준 16946: 벽 부수고 이동하기 4(골드 II), https://www.acmicpc.net/problem/16946
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <deque>
#include <map>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1000;

int N, M, cNumber = 1;
char inputNumbers[MAX+10];
int graph[MAX][MAX], componentGraph[MAX][MAX], answer[MAX][MAX];
bool visited[MAX][MAX];
map<int, int> component;

// U, D, L, R
int dx[4] = {-1, +1, +0, +0};
int dy[4] = {+0, +0, -1, +1};
bool inRange(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    return false;
}

void bfs(pii start){
    int cnt = 1;
    deque<pii> dq;

    dq.push_back(start);
    componentGraph[start.first][start.second] = cNumber;
    visited[start.first][start.second] = true;

    while(!dq.empty()){
        int cx = dq.front().first, cy = dq.front().second;
        dq.pop_front();

        for(int i=0; i<4; ++i){
            int nx = cx + dx[i], ny = cy + dy[i];

            if(!inRange(nx, ny)) continue;
            if(graph[nx][ny] == 1) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            dq.push_back(pii(nx, ny));
            componentGraph[nx][ny] = cNumber;
            ++cnt;
        }
    }
    component[cNumber++] = cnt;
}

int main(){
    // 입력
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; ++i){
        scanf("%s", inputNumbers);
        for(int j=0; j<M; ++j)
            graph[i][j] = inputNumbers[j] - '0';
    }

    // 처리 1: Get componentGraph
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(graph[i][j] == 1) continue;
            if(componentGraph[i][j] != 0) continue;
            bfs(pii(i, j));
        }
    }

    // 처리 2: Fill answer
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(graph[i][j] == 0) continue;

            answer[i][j] = 1;
            bool componentVisited[cNumber];
            fill_n(componentVisited, cNumber, false);

            componentVisited[0] = true;
            for(int d=0; d<4; ++d){
                int nx = i + dx[d], ny = j + dy[d];
                if(!inRange(nx, ny)) continue;
                if(graph[nx][ny] == 1) continue;
                
                int cNum = zeroCount[nx][ny];
                if(componentVisited[cNum]) continue;
                componentVisited[cNum] = true;
                answer[i][j] += component[cNum];
            }
            answer[i][j] %= 10;
        }
    }

    // 출력
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j)
            printf("%d", answer[i][j]);
        printf("\n");
    }

    return 0;
}
