#include <iostream>
using namespace std;

const int MAX = 36;
int N;
long long dp[MAX], temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> N;

    // 처리
    dp[0] = 1;
    for(int i=1; i<=N; ++i){
        temp = 0;
        for(int j=0; j<i; ++j)
            temp += dp[j] * dp[i-j-1];
        dp[i] = temp;
    }

    // 출력
    cout << dp[N] << '\n';

    return 0;
}
