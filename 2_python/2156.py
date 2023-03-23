# 백준 2156: 포도주 시식(실버 I), https://www.acmicpc.net/problem/2156
import sys
input = sys.stdin.readline

MAX = 10000

N = int(input())
grape = [0 for _ in range(MAX+1)]
for i in range(1, N+1):
    grape[i] = int(input())

dp = [0 for _ in range(MAX+1)]

# 고묵호(문과, 27세): 대체 어떻게 이런 식을 자유자재로 빠르게 떠올리고 구현할 수 있는 것이지?
dp[1] = grape[1]
dp[2] = grape[1] + grape[2]
dp[3] = max(dp[2], grape[1] + grape[3], grape[2] + grape[3])

for i in range(4, N+1):
    dp[i] = max(dp[i-1], dp[i-3] + grape[i-1] + grape[i], dp[i-2] + grape[i])

print(dp[N])
