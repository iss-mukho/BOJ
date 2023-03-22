// 백준 11143: Beads(골드 I), https://www.acmicpc.net/problem/11143
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int tree[MAX * 4];
int T, B, P, Q, a, b, startIndex = 1;
char c[2];

void init(){
    while(startIndex <= B)
        startIndex *= 2;       
}

void add(int index, int number){
    while(index > 0){
        tree[index] += number;
        index /= 2;
    }
}

int getSum(int left, int right){
    int ans = 0;
    while(left <= right){
        if(left % 2 == 1) ans += tree[left++];
        if(right % 2 == 0) ans += tree[right--];
        left /= 2;
        right /= 2;
    }
    return ans;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &B, &P, &Q);
        init();

        for(int i=0; i<P+Q; ++i){
            scanf("%s %d %d", &c, &a, &b);
            if(c[0] == 'P') add(startIndex + a - 1, b);
            else printf("%d\n", getSum(startIndex + a - 1, startIndex + b - 1));
        }

        fill_n(tree, MAX*4, 0);
        startIndex = 1;
    }
    
    return 0;
}
