# 백준, 키 순서(골 VI), https://www.acmicpc.net/problem/2458

import sys
input = sys.stdin.readline
INF = int(1e9)

answer = 0
N, M = map(int, input().split())

info = [[INF for _ in range(N)] for _ in range(N)]
for _ in range(M):
    short, long = map(int, input().split())
    info[short-1][long-1] = 1

for m in range(N):
    for s in range(N):
        for e in range(N):
            info[s][e] = min(info[s][e], info[s][m] + info[m][e])

counting = [0 for _ in range(N)]
for i in range(N):
    for j in range(N):
        if info[i][j] < INF:
            counting[i] += 1
            counting[j] += 1

for i in range(N):
    if counting[i] == N-1:
        answer += 1
print(answer)
