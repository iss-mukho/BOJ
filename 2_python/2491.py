# 백준 2491: 수열(실버 IV), https://www.acmicpc.net/problem/2491
import sys
input = sys.stdin.readline

answer = 1
N = int(input())
number = list(map(int, input().split()))

u = d = 1
for i in range(1, N):
    u = u+1 if number[i-1] <= number[i] else 1
    d = d+1 if number[i-1] >= number[i] else 1
    answer = max(answer, u, d)

print(answer)
