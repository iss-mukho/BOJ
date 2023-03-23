// 백준 2747: 피보나치 수(브론즈 II), https://www.acmicpc.net/problem/2747
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 45;

int n;
int fibo[MAX+1];

int main(){
    scanf("%d", &n);

    fibo[0] = 0;
    fibo[1] = 1;

    for(int i=2; i<=n; ++i)
        fibo[i] = fibo[i-2] + fibo[i-1];
    
    printf("%d\n", fibo[n]);

    return 0;
}
