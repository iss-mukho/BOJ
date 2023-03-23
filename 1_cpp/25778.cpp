// 백준 25778: House Prices Going Up(골드 I), https://www.acmicpc.net/problem/25778
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef long long ll;
const ll MAX = 500000;

ll number[MAX];
ll tree[MAX * 4];
ll N, T, a, b, startIndex = 1;
char c[2];

void init(){
    while(startIndex <= N)
        startIndex *= 2;   
    for(ll i=0; i<N; ++i)
        tree[startIndex + i] = number[i];
    for(ll i=startIndex-1; i>0; --i)
        tree[i] = tree[i*2] + tree[i*2+1];    
}

void update(ll index, ll number){
    while(index > 0){
        tree[index] += number;
        index /= 2;
    }
}

ll getSum(ll left, ll right){
    ll ans = 0;
    while(left <= right){
        if(left % 2 == 1) ans += tree[left++];
        if(right % 2 == 0) ans += tree[right--];
        left /= 2;
        right /= 2;
    }
    return ans;
}

int main(){
    scanf("%lld", &N);
    for(ll i=0; i<N; ++i)
        scanf("%lld", &number[i]);
    init();
    scanf("%lld", &T);
    for(ll i=0; i<T; ++i){
        scanf("%s %lld %lld", &c, &a, &b);
        if(c[0] == 'U') update(startIndex + a - 1, b);
        else printf("%lld\n", getSum(startIndex + a - 1, startIndex + b - 1));
    }

    return 0;
}
