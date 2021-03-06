#include <iostream>
#include <queue>
using namespace std;

void DFS(int** g, int n, int v);
void BFS(int** g, int n, int v);
int search_dfs[1000];
int search_bfs[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 문제에서 1번부터 N번까지이나, 코드는 0번부터 N-1번까지임.
    int N, M, V;
    cin >> N >> M >> V;
    V -= 1; // 변환

    // 동적할당
    int** graph = new int* [N];
    for (int i = 0; i < N; i++)
        graph[i] = new int[N];
    
    // 초기화
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        // 양방향
        graph[s-1][e-1] = 1;
        graph[e-1][s-1] = 1;
    }

    DFS(graph, N, V);
    cout << '\n';
    BFS(graph, N, V);
    cout << '\n';

    return 0;
}

// 스택처럼 구현
void DFS(int** g, int n, int v) {
    search_dfs[v] = 1;
    cout << v+1 << " ";
    for (int i = 0; i < n; i++) {
        int next = g[v][i];
        if (next == 1)
            if (search_dfs[i] == 0)
                DFS(g, n, i);
    }
}

// 큐 사용
void BFS(int** g, int n, int v) {
    queue<int> q;
    q.push(v);
    search_bfs[v] = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current+1 << " ";

        for (int i = 0; i < n; i++) {
            int next = g[current][i];
            if (next == 1)
                if (search_bfs[i] == 0){
                    search_bfs[i] = 1;
                    q.push(i);
                }
        }
    }
}
