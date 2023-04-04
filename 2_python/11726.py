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

<<<<<<< HEAD
print(dp[n])
=======
print(dp[n] % 10007)
>>>>>>> 24b9fdbc6beb71d61f8d83eb03022f4e46a393a1
