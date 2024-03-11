import sys
input = sys.stdin.readline

N, M = map(int, input().split())

table = [list(map(int, input().split())) for _ in range(N)]
dp = [[0 for _ in range(N + 1)] for _ in range(N + 1)]

# 초기화
dp[1][1] = table[0][0]
for i in range(2, N + 1):
  dp[1][i] = dp[1][i - 1] + table[0][i - 1]
  dp[i][1] = dp[i - 1][1] + table[i - 1][0]

# 계산
for i in range(2, N + 1):
  for j in range(2, N + 1):
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + table[i - 1][j - 1]

for _ in range(M):
  x1, y1, x2, y2 = map(int, input().split())
  print(dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1])
