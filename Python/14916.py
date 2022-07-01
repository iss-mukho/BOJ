INF = 9999999999
N = int(input())
dp = [INF] * 100001

if N in [1, 3]:
    print(-1)
else:
    dp[2] = dp[5] = 1
    dp[4] = 2
    for i in range(6, N+1):
        dp[i] = min(dp[i-2], dp[i-5])+1
    
print(dp[N])
