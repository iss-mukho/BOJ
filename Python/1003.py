# 백준 1003: 피보나치 함수(실버 III), https://www.acmicpc.net/problem/1003
import sys
input = sys.stdin.readline

MAX = 40

dp = [0 for _ in range(MAX+1)]
dp[0] = 0
dp[1] = 1
for i in range(2, MAX+1):
    dp[i] = dp[i-2] + dp[i-1]

T = int(input())
for _ in range(T):
    N = int(input())

    if N == 0:
        print(f"{1} {0}")
    else:
        print(f"{dp[N-1]} {dp[N]}")
