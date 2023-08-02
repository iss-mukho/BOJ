MAX = 10000

dp = [[0 for _ in range(4)] for _ in range(MAX + 1)]
for i in range(1, 4):
    for j in range(1, i + 1):
        dp[i][j] = 1

for i in range(4, MAX + 1):
    dp[i][1] = dp[i - 1][1]
    dp[i][2] = dp[i - 2][1] + dp[i - 2][2]
    dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]

for _ in range(int(input())):
    n = int(input())
    print(dp[n][1] + dp[n][2] + dp[n][3])