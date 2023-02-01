// 백준 2623 음악 프로그램(골드 III)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

const int MAX = 1000;
int N, M, C, before, after;
int indegree[MAX + 1];
vector<int> graph[MAX + 1];
deque<int> dq;
vector<int> answer;

void topology_sort() {
    for (int i = 1; i <= N; ++i)
        if (indegree[i] == 0)
            dq.push_back(i);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        answer.push_back(cur);

        for (auto next : graph[cur]) {
            --indegree[next];
            if (indegree[next] == 0)
                dq.push_back(next);
        }
    }
}

int main() {
    // 입력
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; ++i) {
        scanf("%d", &C);
        for (int j = 0; j < C; ++j) {
            scanf("%d", &after);

            if (j == 0) {
                before = after;
                continue;
            }

            graph[before].push_back(after);
            ++indegree[after];
            before = after;
        }
    }

    // 처리: 위상 정렬
    topology_sort();

    // 출력
    if (answer.size() != N) printf("%d\n", 0);
    else for (auto n : answer) printf("%d\n", n);

    return 0;
}