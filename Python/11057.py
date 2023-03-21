# 백준 11057: 오르막 수(실버 I), https://www.acmicpc.net/problem/11057
MAX = 1000

N = int(input())
dp = [[0 for _ in range(10)] for _ in range(MAX+1)]

for i in range(10):
    dp[1][i] = 1

for i in range(2, N+1):
    for j in range(10):
        for k in range(j, 10):
            dp[i][k] += dp[i-1][j]

print(sum(dp[N]) % 10007)
