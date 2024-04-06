import sys

input = sys.stdin.readline


N = int(input())
numbers = [0] + list(int(input()) for _ in range(N))
dp = [0 for _ in range(N + 1)]

lis = 0
for i in range(1, N + 1):
  dp[i] = 1

  for j in range(1, N + 1):
    if numbers[j] >= numbers[i]: continue
    if dp[i] >= dp[j] + 1: continue
    dp[i] += 1

  if lis < dp[i]:
    lis = dp[i]

print(N - lis)
