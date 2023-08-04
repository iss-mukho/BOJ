INF = int(1e9)
MAX = 5001

dp = [INF] * MAX
dp[3] = 1
dp[5] = 1
for i in range(6, MAX):
    dp[i] = min(dp[i - 3] + dp[i - 5], dp[i - 3] + 1, dp[i - 5] + 1)

N = int(input())
print(dp[N] if dp[N] < INF else -1)
