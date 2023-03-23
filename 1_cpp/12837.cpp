// 백준 12837: 가계부 (Hard)(골드 I), https://www.acmicpc.net/problem/12837
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef long long ll;
const ll MAX = 1000000;

ll tree[MAX * 4];
ll N, Q, c, p, x, q, startIndex = 1;

void init(){
    while(startIndex <= N)
        startIndex *= 2;
}

void add(ll index, ll number){
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
    scanf("%lld %lld", &N, &Q);
    init();

    for(ll i=0; i<Q; ++i){
        scanf("%lld", &c);

        if(c == 1){
            scanf("%lld %lld", &p, &x);
            add(startIndex + p - 1, x); // 변경 X, 추가 O
        }
        else{
            scanf("%lld %lld", &p, &q);
            printf("%lld\n", getSum(startIndex + p - 1, startIndex + q - 1));
        }
    }

    return 0;
}
