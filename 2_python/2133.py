# 백준 2133: 타일 채우기(골드 IV): https://www.acmicpc.net/problem/2133
N = int(input())

dp = [0] * (N+1)
dp[0] = 1

for index in range(2, N+1, 2):
    beforeIndex = index-2
    dp[index] += dp[beforeIndex] * 3
    for i in range(beforeIndex-2, -1, -2):
        dp[index] += dp[i] * 2

print(dp[N])
