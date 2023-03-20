// 백준 27727: 버튼 정렬(골드 II), https://www.acmicpc.net/problem/27727
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 100000;

ll N, K, nCount = 0, answer = 0;
ll A[MAX], B[MAX];

int main(){
    // 입력
    scanf("%lld", &N);
    for(int i=0; i<N; ++i){
        scanf("%lld", &A[i]);
        B[i] = A[i];
    }
    scanf("%lld", &K);

    // 처리 1: 주기성을 가지기 이전 처리
    

    // 처리 2: 주기성 처리
    sort(B, B + N);
    for(int i=0; i<N-1; ++i)
        nCount += (B[N-1] - B[i]);

    answer += (K - nCount) / N;

    // 출력
    printf("%lld\n", answer);

    return 0;
}