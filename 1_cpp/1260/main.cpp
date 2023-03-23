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

    // 문제에서 정점 번호는 1번부터 N번까지이나, 코드는 0번부터 N-1번까지임.
    int N, M, V; // N = 정점 수, M = 간선 수, V = 탐색을 시작할 정점의 번호 
    cin >> N >> M >> V;
    V -= 1; // 변환

    // 그래프 : 배열을 통해 구현
    // 동적할당
    int** graph = new int* [N];
    for (int i = 0; i < N; i++)
        graph[i] = new int[N];
    
    // 그래프 초기화
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    // 간선 정보
    for (int i = 0; i < M; i++) {
        int s, e; // start, end
        cin >> s >> e;

        // 양방향. 1번 정점이 코드상 0번임
        graph[s-1][e-1] = 1;
        graph[e-1][s-1] = 1;
    }

    DFS(graph, N, V);
    cout << '\n';
    BFS(graph, N, V);
    cout << '\n';

    return 0;
}

// 스택(LIFO)처럼 구현(?). 재귀
void DFS(int** g, int n, int v) {
    search_dfs[v] = 1; // 해당 정점 탐색 on
    cout << v+1 << " "; // 정점 번호를 문제에 맞게 변환
    for (int i = 0; i < n; i++) { // 한쪽 파고들고 다음 다음 다음..
        int next = g[v][i]; // 다음 탐색 정점은, 해당 정점에서 간선과 이어져있는 정점이어야 한다.
        if (next == 1) // 이어져있는가?
            if (search_dfs[i] == 0) // 탐색안한 정점인가?
                DFS(g, n, i); // 파고들어가자
    }
}

// 큐 사용(FIFO)
void BFS(int** g, int n, int v) {
    queue<int> q; // 가로로 봤을때 정점 저장.
    q.push(v); // 해당 정점 저장
    search_bfs[v] = 1; // 해당 정점 탐색 on

    while(!q.empty()){ // q가 비면 모든 정점을 탐색한 것이다.
        int current = q.front(); // 지금 보는 정점 == queue 맨 앞에 있음.
        q.pop(); // 봤으니까 queue에서 제거
        cout << current+1 << " "; // 정점 번호를 문제에 맞게 변환

        for (int i = 0; i < n; i++) { // 해당 정점에서 뻗어나가는 간선에 이어진 정점들을 모두 queue에 push
            int next = g[current][i]; // // 다음 탐색 정점은, 해당 정점에서 간선과 이어져있는 정점들이다.
            if (next == 1) // 이어져있는가?
                if (search_bfs[i] == 0){  // 탐색안한 정점인가?
                    search_bfs[i] = 1; // 해당 정점 탐색 on
                    q.push(i); // queue에 정점 저장
                }
        }
    }
}
