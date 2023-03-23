// ���� 2211 ��Ʈ��ũ ����(��� II)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (-C, B)
const int INF = 2100000000;
const int MAX = 1000;
vector<pii> edges[MAX + 1];
priority_queue<pii> pq;
vector<pii> answer[MAX + 1]; // (S, E)
int N, M, A, B, C, K;
int dist[MAX + 1];

void dijkstra(int start) {
    dist[start] = 0;
    pq.push(pii(-0, start));

    while (!pq.empty()) {
        int s = pq.top().second, w = -pq.top().first;
        pq.pop();

        if (dist[s] < w) continue;

        for (auto next : edges[s]) {
            int e = next.second, ew = next.first + w;
            if (dist[e] > ew) {
                dist[e] = ew;
                pq.push(pii(-ew, e));

                if (!answer[e].empty()) { // ���� �ִ� ���� ������ �ִٸ� ����
                    answer[e].pop_back();
                    --K;
                }
                answer[e].push_back(pii(s, e)); // �ִ� �Ÿ� ���Ž�, ����� ���� ������ ����
                ++K;
            }
        }
    }
}

int main() {
    // �Է�
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &A, &B, &C);
        edges[A].push_back(pii(C, B));
        edges[B].push_back(pii(C, A)); // ��� ����� �����ֹ��� ������� �̷������ ������
    }

    // ó��: ���ͽ�Ʈ��
    fill_n(dist + 1, N, INF);
    dijkstra(1); // 1�� ��ǻ�ʹ� ���� �ý����� ��ġ�� ������ǻ���̴�.

    // ���
    printf("%d\n", K);
    for (int i = 1; i <= N; ++i)
        for (auto line : answer[i])
            printf("%d %d\n", line.first, line.second);

    return 0;
}