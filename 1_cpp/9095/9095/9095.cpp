#include <iostream>
using namespace std;

const int MAX = 11;
int dp[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= MAX; ++i)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
