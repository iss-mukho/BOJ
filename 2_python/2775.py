# 백준 2775: 부녀회장이 될테야(브론즈 I), https://www.acmicpc.net/problem/2775
MAX = 15
dp = [[0 for _ in range(MAX)] for _ in range(MAX)]
for i in range(1, MAX):
    dp[0][i] = i
for i in range(1, MAX):
    for j in range(1, MAX):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]

T = int(input())
for _ in range(T):
    k = int(input())
    n = int(input())
    print(dp[k][n])
