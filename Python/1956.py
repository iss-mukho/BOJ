# 백준, 운동(골 VI), https://www.acmicpc.net/problem/1956

import sys
input = sys.stdin.readline
INF = int(1e9)

V, E = map(int, input().split())
graph = [[INF for _ in range(V)] for _ in range(V)]

for _ in range(E):
    s, e, w = map(int, input().split())
    graph[s-1][e-1] = w

for m in range(V):
    for s in range(V):
        for e in range(V):
            graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e])

answer = INF
for i in range(V):
    if answer > graph[i][i]:
        answer = graph[i][i]

print(answer if answer != INF else -1)
