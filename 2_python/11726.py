# 백준 11726: 2xn 타일링(실버 III), https://www.acmicpc.net/problem/11726
import sys
input = sys.stdin.readline
INF = 1000

dp = [INF for _ in range(INF+1)]
n = int(input())

dp[1] = 1
dp[2] = 2
for i in range(3, n+1):
    dp[i] = dp[i-2] + dp[i-1]

print(dp[n])
