import sys

input = sys.stdin.readline

N, K = map(int, input().split())

info = [list(map(int, input().split())) for _ in range(N)]
dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
  weight, value = info[i - 1]

  for w in range(1, K + 1):
    if w < weight:
      dp[i][w] = dp[i - 1][w]
    else:
      dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight] + value)

print(dp[N][K])
