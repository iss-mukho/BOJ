// 백준 27727: 버튼 정렬(골드 II), https://www.acmicpc.net/problem/27727
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 100000;

ll N, K, maxNum, A[MAX];

ll getAnswer() {
    if (K < 0) return 0;

    ll answer = maxNum > 0;
    int i = 0, j = 1;
    while (i < N) {
        while (j < N && A[i] == A[j]) ++j;

        if (j == N) {
            answer += K / N;
            break;
        }

        ll temp = min(K / j, A[j] - A[i]);
        answer += temp;
        K -= j * temp;

        i = j++;
    }

    return answer;
}

int main() {
    scanf("%lld", &N);
    for (int i = 0; i < N; ++i)
        scanf("%lld", &A[i]);
    scanf("%lld", &K);

    for (int i = 1; i < N; ++i) {
        if (A[i - 1] <= A[i]) continue;
        
        K -= A[i - 1] - A[i];
        maxNum = A[i] = A[i - 1];
    }

    for (int i = 0; i < N; ++i) {
        if (A[i] >= maxNum) continue;

        K -= maxNum - A[i];
        A[i] = maxNum;
    }

    printf("%lld\n", getAnswer());

    return 0;
}
