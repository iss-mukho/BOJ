# 백준 11055: 가장 큰 증가하는 부분 수열(실버 II), https://www.acmicpc.net/problem/11055
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
dp = A[:]

for i in range(N-1):
    for j in range(i+1, N):
        if A[i] >= A[j]: continue
        dp[j] = max(dp[j], dp[i] + A[j])

print(max(dp))
