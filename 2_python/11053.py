N = int(input())
A = list(map(int, input().split()))

dp = [1] * N
for r in range(N):
    for l in range(r):
        if A[l] < A[r]:
            dp[r] = max(dp[r], dp[l] + 1)

print(max(dp))