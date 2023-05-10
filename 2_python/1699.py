# 백준 1699: 제곱수의 합(실버 II), https://www.acmicpc.net/problem/1699
N = int(input())
dp = [i for i in range(N + 1)]
for i in range(1, N + 1):
    j = 1
    while j * j <= i:
        dp[i] = min(dp[i], dp[i - j * j] + 1)
        j += 1
print(dp[N])
