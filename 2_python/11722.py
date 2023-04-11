# 백준 11722: 가장 긴 감소하는 부분 수열(실버 II), https://www.acmicpc.net/problem/11722
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
dp = [1] * N

for i in range(N-1):
    for j in range(i+1, N):
        if A[i] <= A[j]: continue
        dp[j] = max(dp[j], dp[i] + 1)

print(max(dp))
