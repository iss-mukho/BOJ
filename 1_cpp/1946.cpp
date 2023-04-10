// 백준 1946: 신입 사원(실버 I), https://www.acmicpc.net/problem/1946
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int T, N, f, s, sMin, cnt = 1;
vector<pii> v;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);

        for(int i=0; i<N; ++i){
            scanf("%d %d", &f, &s);
            v.push_back(pair(f, s));
        }

        sort(v.begin(), v.end());

        sMin = v.front().second;
        for(int i=1; i<N; ++i){
            if(v[i].second > sMin) continue;
            sMin = v[i].second;
            ++cnt;
        }

        printf("%d\n", cnt);

        v.clear();
        cnt = 1;
    }

    return 0;
}
