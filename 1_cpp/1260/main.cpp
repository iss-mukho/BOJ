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

    // �������� ���� ��ȣ�� 1������ N�������̳�, �ڵ�� 0������ N-1��������.
    int N, M, V; // N = ���� ��, M = ���� ��, V = Ž���� ������ ������ ��ȣ 
    cin >> N >> M >> V;
    V -= 1; // ��ȯ

    // �׷��� : �迭�� ���� ����
    // �����Ҵ�
    int** graph = new int* [N];
    for (int i = 0; i < N; i++)
        graph[i] = new int[N];
    
    // �׷��� �ʱ�ȭ
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    // ���� ����
    for (int i = 0; i < M; i++) {
        int s, e; // start, end
        cin >> s >> e;

        // �����. 1�� ������ �ڵ�� 0����
        graph[s-1][e-1] = 1;
        graph[e-1][s-1] = 1;
    }

    DFS(graph, N, V);
    cout << '\n';
    BFS(graph, N, V);
    cout << '\n';

    return 0;
}

// ����(LIFO)ó�� ����(?). ���
void DFS(int** g, int n, int v) {
    search_dfs[v] = 1; // �ش� ���� Ž�� on
    cout << v+1 << " "; // ���� ��ȣ�� ������ �°� ��ȯ
    for (int i = 0; i < n; i++) { // ���� �İ��� ���� ���� ����..
        int next = g[v][i]; // ���� Ž�� ������, �ش� �������� ������ �̾����ִ� �����̾�� �Ѵ�.
        if (next == 1) // �̾����ִ°�?
            if (search_dfs[i] == 0) // Ž������ �����ΰ�?
                DFS(g, n, i); // �İ����
    }
}

// ť ���(FIFO)
void BFS(int** g, int n, int v) {
    queue<int> q; // ���η� ������ ���� ����.
    q.push(v); // �ش� ���� ����
    search_bfs[v] = 1; // �ش� ���� Ž�� on

    while(!q.empty()){ // q�� ��� ��� ������ Ž���� ���̴�.
        int current = q.front(); // ���� ���� ���� == queue �� �տ� ����.
        q.pop(); // �����ϱ� queue���� ����
        cout << current+1 << " "; // ���� ��ȣ�� ������ �°� ��ȯ

        for (int i = 0; i < n; i++) { // �ش� �������� ������� ������ �̾��� �������� ��� queue�� push
            int next = g[current][i]; // // ���� Ž�� ������, �ش� �������� ������ �̾����ִ� �������̴�.
            if (next == 1) // �̾����ִ°�?
                if (search_bfs[i] == 0){  // Ž������ �����ΰ�?
                    search_bfs[i] = 1; // �ش� ���� Ž�� on
                    q.push(i); // queue�� ���� ����
                }
        }
    }
}
