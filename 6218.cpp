// 백준 6218: Balanced Lineup(골드 I), https://www.acmicpc.net/problem/6218
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii; // (min, max)
const int MAX = 50000;

int number[MAX];
pii tree[MAX * 4];
int N, Q, n, A, B, startIndex = 1;

void init(){
    while(startIndex <= N)
        startIndex *= 2;
    for(int i=0; i<N; ++i)
        tree[startIndex + i] = pii(number[i], number[i]);
    for(int i=startIndex-1; i>0; --i){
        int low = min(tree[i*2].first, tree[i*2+1].first);
        int high = max(tree[i*2].second, tree[i*2+1].second);
        tree[i] = pii(low, high);
    }       
}

int getRange(int left, int right){
    int low = 1000000, high = 1;
    while(left <= right){
        if(left % 2 == 1){
            low = min(low, tree[left].first);
            high = max(high, tree[left].second);
        }
        if(right % 2 == 0){
            low = min(low, tree[right].first);
            high = max(high, tree[right].second);
        }
        left = (left + 1) / 2;
        right = (right - 1) / 2;
    }
    return high - low;
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i=0; i<N; ++i)
        scanf("%d", &number[i]);
    init();
    for(int i=0; i<Q; ++i){
        scanf("%d %d", &A, &B);
        printf("%d\n", getRange(startIndex + A - 1, startIndex + B - 1));
    }

    return 0;
}
