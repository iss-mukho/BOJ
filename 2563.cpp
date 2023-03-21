// 백준 2563: 색종이(실버 V), https://www.acmicpc.net/problem/2563
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 100;

int n, a, b, area = 0;
bool paper[MAX][MAX];

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; ++i){
        scanf("%d %d", &a, &b);

        for(int i=0; i<10; ++i)
            for(int j=0; j<10; ++j)
                paper[a+i][b+j] = true;
    }

    for(int i=0; i<MAX; ++i){
        for(int j=0; j<MAX; ++j){
            if(!paper[i][j]) continue;
            ++area;
        }
    }

    printf("%d\n", area);

    return 0;
}
