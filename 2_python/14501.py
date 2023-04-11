# 백준 14501: 퇴사(실버 III), https://www.acmicpc.net/problem/14501
import sys
input = sys.stdin.readline

N = int(input())

dp = [0 for _ in range(N+1)]
TP = [[0, 0]]
for _ in range(N):
    TP.append(list(map(int, input().split())))

for i in range(1, N+1):
    t, p = TP[i]
    dp[i] = max(dp[i], dp[i-1])
    
    idx = i + t - 1
    if idx > N: continue
    dp[idx] = max(dp[idx], dp[i-1] + p)

print(max(dp))
