# 백준 1437: 수 분해(골드 IV), https://www.acmicpc.net/problem/1437
MOD = 10007
dp = [0] * (1000001)
dp[0] = 0
dp[1] = 1
dp[2] = 2
dp[3] = 3

N = int(input())
for i in range(4, N+1):
    num = pow(3, (i-4)//3) * ((i-1) % 3 + 1)
    dp[i] = (dp[i-1] + num) % MOD

print(dp[N])
