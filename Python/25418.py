# 백준 25418: 정수 a를 k로 만들기(실버III), https://www.acmicpc.net/problem/25418
import sys
input = sys.stdin.readline
MAX = 1000000

A, K = map(int, input().split())

dp = [MAX+1 for _ in range(MAX+1)]
dp[A] = 0
dp[A+1] = 1

for i in range(A+1, K+1):
    if i % 2 == 0: dp[i] = min(dp[i], min(dp[i-1], dp[i//2]) + 1)
    else: dp[i] = min(dp[i], dp[i-1] + 1)

print(dp[K])
