# 백준 2193: 이친수(실버 III), https://www.acmicpc.net/problem/2193
MAX = 90

N = int(input())
dp = [0 for _ in range(MAX+1)]

dp[1] = 1
dp[2] = 1
for i in range(3, N+1):
    dp[i] = dp[i-2] + dp[i-1]

print(dp[N])
