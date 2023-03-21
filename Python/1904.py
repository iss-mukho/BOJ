# 백준 1904: 01타일(실버 III), https://www.acmicpc.net/problem/1904
MAX = 1000000

N = int(input())

dp = [0 for _ in range(MAX+1)]
dp[1] = 1
dp[2] = 2

for i in range(3, N+1):
    dp[i] = (dp[i-2] + dp[i-1]) % 15746

print(dp[N])