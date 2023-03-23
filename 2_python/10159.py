# 백준: 저울(골 IV), https://www.acmicpc.net/problem/10159

import sys
input = sys.stdin.readline
INF = int(1e9)

N = int(input())
M = int(input())
graph = [[INF for _ in range(N)] for _ in range(N)]

for _ in range(M):
    h, l = map(int, input().split())
    graph[h-1][l-1] = 1
for i in range(N):
    graph[i][i] = 0

for m in range(N):
    for s in range(N):
        for e in range(N):
            graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e])

for i in range(N):
    cnt = 0
    for j in range(N):
        if i == j:
            continue
        if graph[i][j] == INF:
            if graph[j][i] != INF:
                continue
            cnt += 1
    print(cnt)
