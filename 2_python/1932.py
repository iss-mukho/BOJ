import sys
input = sys.stdin.readline

N = int(input())
tri = []
for _ in range(N):
    tri.append(list(map(int, input().split())))

dp = [[0 for _ in range(N)] for _ in range(N)]

dp[0][0] = tri[0][0]
for i in range(1, N):
    for j in range(i + 1):
        if j == 0:
            dp[i][j] = dp[i-1][j] + tri[i][j]
        elif j == i:
            dp[i][j] = dp[i-1][j-1] + tri[i][j]
        else:
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j]

print(max(dp[N-1]))
