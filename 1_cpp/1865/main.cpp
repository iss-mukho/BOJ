// ���� 1865 ��Ȧ(��� III)
/**
 * �������� ���� -> ����-���� �Լ��� �Ű� ���� (int start) ����
 *     - ����, ����-���� �˰����� "�������� INF�� �ƴϰ�"�� ����
 *     - ����� ������ ���� �־��� ��, ���� ó���� ����
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

            if (dist[E] > dist[S] + T) { // �������� ������ ���� ����
                dist[E] = dist[S] + T;
                if (i == N) return false;
            }
        }
    }
    return true;
}

int main() {
    // �Է�
    scanf("%d", &TC);
    while (TC--) {
        init();
        scanf("%d %d %d", &N, &M, &W);

        // �� ���δ� ������ ������ ��Ȧ�� ������ �ִ�.
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &S, &E, &T);
            edges.push_back(edgeType(T, pii(S, E)));
            edges.push_back(edgeType(T, pii(E, S)));
        }
        for (int i = 0; i < W; ++i) {
            scanf("%d %d %d", &S, &E, &T);
            edges.push_back(edgeType(-T, pii(S, E)));
        }

        // ó�� �� ���: ����-���� �˰���
        if (!ballmanFord()) printf("YES\n"); // ���� ����Ŭ ���� = �ð��� �پ��鼭 ���������� ���ƿ� �� ����
        else printf("NO\n");
    }

    return 0;
}