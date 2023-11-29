N = int(input())

T = [0] * N
P = [0] * N

for i in range(N):
    T[i], P[i] = map(int, input().split())

dp = [0] * (N + 1)

for i in range(N):
    j = i + T[i]
    if j > N:
        dp[i] = dp[i - 1]
        continue

    dp[i] = max(dp[j] + P[i], dp[i - 1])

print(dp[0])
