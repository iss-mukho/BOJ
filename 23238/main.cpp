#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 100000;
struct S {
    int x, y, num, cnt, ans;
} Q[MAX + 1];

// countArray: �ش� index�� ���ڰ� �󸶳� �����ߴ°�
// countArrayInQuery: ���� �������� �ش� index�� ���ڰ� �󸶳� �����ߴ°�
int N, M, A[MAX + 1], sn, s, e, cMax, nMax = 0, countArray[MAX + 1], countArrayInQuery[MAX + 1];

// ���� ����
bool cmp1(S a, S b) {
    if (a.x / sn == b.x / sn) return a.y < b.y;
    return a.x / sn < b.x / sn;
}
bool cmp2(S a, S b) {
    return a.num < b.num;
}

// mo's algorithm
void up(int idx) {
    --countArrayInQuery[countArray[idx]];
    if (countArray[idx] == cMax) {
        ++cMax;
        nMax = idx;
    }
    ++countArray[idx];
    if (countArray[idx] == cMax) {
        if (nMax < idx) {
            nMax = idx;
        }
    }
    ++countArrayInQuery[countArray[idx]];
}
void down(int idx) {
    if (countArray[idx] < cMax) {
        if (countArrayInQuery[cMax] == 0) --cMax;
        return;
    }

    if (countArrayInQuery[cMax] == 0) {
        --cMax;
        for (int i = MAX; i >= 0; --i) {
            if (countArrayInQuery[i] > 0) {
                cMax = i;
                nMax = countArray[cMax];
                break;
            }
        }
    }
    else {
        nMax = countArray[cMax];
    }
}

int main() {
    // �Է�
    scanf("%d %d", &N, &M);
    sn = (int)sqrt(N) + 1;

    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);

    for (int i = 1; i <= M; ++i) {
        scanf("%d %d", &Q[i].x, &Q[i].y);
        Q[i].num = i;
    }

    // ó��
    countArrayInQuery[0] = 0;
    sort(Q + 1, Q + M + 1, cmp1);
    for (int i = Q[1].x; i <= Q[1].y; ++i)
        up(A[i]);

    s = Q[1].x; e = Q[1].y; Q[1].cnt = cMax, Q[1].ans = nMax;
    for (int i = 2; i <= M; ++i) {
        while (e < Q[i].y) up(A[++e]);
        while (s > Q[i].x) up(A[--s]);
        while (e > Q[i].y) down(A[e--]);
        while (s < Q[i].x) down(A[s++]);

        Q[i].cnt = cMax;
        Q[i].ans = nMax;
    }

    // ���
    sort(Q + 1, Q + M + 1, cmp2);
    for (int i = 1; i <= M; ++i)
        printf("%d\n", Q[i].ans);

    return 0;
}