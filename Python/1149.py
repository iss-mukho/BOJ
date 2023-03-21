# 백준 RGB거리(실버 I), https://www.acmicpc.net/problem/1149
import sys
input = sys.stdin.readline

INF = 10000000

N = int(input())
house = []
for _ in range(N):
    house.append(list(map(int, input().split())))

dp = [[0 for _ in range(3)] for _ in range(N)]
dp[0][0] = house[0][0]
dp[0][1] = house[0][1]
dp[0][2] = house[0][2]

for i in range(1, N):
    for j in range(3):
        minNum = INF
        for k in range(3):
            if j == k: continue
            minNum = min(minNum, dp[i-1][k])

        dp[i][j] = house[i][j] + minNum
        
print(min(dp[N-1]))
