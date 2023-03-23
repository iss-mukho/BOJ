# 백준 10844: 쉬운 계단 수(실버 I), https://www.acmicpc.net/problem/10844
N = int(input())
dp = [[0 for _ in range(10)] for _ in range(N+1)]

for i in range(10):
    dp[1][i] = 1

for i in range(2, N+1):
    dp[i][0] = 1
    for n in range(10):
        if n == 0: dp[i][n] = dp[i-1][n+1]
        elif n == 9: dp[i][n] = dp[i-1][n-1]
        else: dp[i][n] = dp[i-1][n-1] + dp[i-1][n+1]
    
print((sum(dp[N])-dp[N][0]) % 1000000000)