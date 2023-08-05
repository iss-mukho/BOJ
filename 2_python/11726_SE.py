MOD = 10007
MAX = 1001
dp = [0] * MAX
dp[1] = 1
dp[2] = 2

for i in range(3, MAX):
    dp[i] = dp[i - 1] + dp[i - 2]
    dp[i] %= MOD

N = int(input())
print(dp[N])