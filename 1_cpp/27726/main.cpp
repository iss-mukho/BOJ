#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<vector<int>, int> Component;

const int MAX = 100001;

int N, M[3], a, b;
int parent[3][MAX];

vector<Component> components;
vector<int> temp;
vector<vector<int>> answer;

int findParent(int m, int x) {
    if (parent[m][x] != x) parent[m][x] = findParent(m, parent[m][x]);
    return parent[m][x];
}

void unionParent(int m, int a, int b) {
    a = findParent(m, a);
    b = findParent(m, b);

    if (a < b) parent[m][b] = a;
    else parent[m][a] = b;
}

void init() {
    for (int i = 1; i <= N; ++i) {
        parent[0][i] = i;
        parent[1][i] = i;
        parent[2][i] = i;
    }
}

void input() {
    scanf("%d", &N);

    init();

    scanf("%d %d %d", &M[0], &M[1], &M[2]);

    for (int m = 0; m < 3; ++m) {
        for (int i = 0; i < M[m]; ++i) {
            scanf("%d %d", &a, &b);

            if (findParent(m, a) != findParent(m, b)) unionParent(m, a, b);
        }
    }
}

void arrToComp() {
    for (int n = 1; n <= N; ++n) {
        for (int i = 0; i < 3; ++i)
            temp.push_back(findParent(i, parent[i][n]));

        components.push_back(Component(temp, n));
        temp.clear();
    }

    sort(components.begin(), components.end());
}

void addAnswer() {
    if (temp.size() > 1) {
        sort(temp.begin(), temp.end());
        answer.push_back(temp);
    }
    temp.clear();
}

void process() {
    int i = 0, j = 1;

    while (j < N) {
        if (temp.empty()) temp.push_back(components[i].second);

        if (components[i].first == components[j].first) {
            temp.push_back(components[j].second);
        }
        else {
            addAnswer();
            i = j;
        }

        ++j;
    }

    addAnswer();
}

void output() {
    printf("%d\n", answer.size());

    sort(answer.begin(), answer.end());

    for (vector<int> ans : answer) {
        for (int a : ans)
            printf("%d ", a);
        printf("\n");
    }
}

int main() {
    input();
    arrToComp();
    process();
    output();

    return 0;
}