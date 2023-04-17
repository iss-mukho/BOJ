# 백준 2217: 로프(실버 IV), https://www.acmicpc.net/problem/2217
import sys
input = sys.stdin.readline

N = int(input())
rope = []
for _ in range(N):
    rope.append(int(input()))
rope.sort(reverse=True)

answer = 0
for i in range(N):
    if answer < rope[i] * (i+1):
        answer = rope[i] * (i+1)
print(answer)
