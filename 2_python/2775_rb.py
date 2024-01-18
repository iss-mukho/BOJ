MAX = 15

# init
dp = [[0 for _ in range(MAX)] for _ in range(MAX)]

for i in range(1, MAX):
    dp[0][i] = i

# Get DP
for a in range(1, MAX):
    for b in range(1, MAX):
        dp[a][b] += dp[a - 1][b] + dp[a][b - 1]

# Input/Output
for _ in range(int(input())):
    k = int(input())
    n = int(input())
    print(dp[k][n])
