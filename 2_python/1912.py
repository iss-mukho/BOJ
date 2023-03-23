# 백준 1912: 연속합(실버 II), https://www.acmicpc.net/problem/1912
import sys
input = sys.stdin.readline

N = int(input())
number = list(map(int, input().split()))

dp = [0 for _ in range(N)]
dp[0] = number[0]

for i in range(N):
    dp[i] = max(dp[i-1] + number[i], number[i])

print(max(dp))
