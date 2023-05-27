# 백준 13141: Ignition(플래티넘 V), https://www.acmicpc.net/problem/13141
import sys
input = sys.stdin.readline
INF = int(1e10)

N, M = map(int, input().split())
graph = [[INF for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(1, N + 1):
    graph[i][i] = 0
fire = [[0 for _ in range(N + 1)] for _ in range(N + 1)]

for _ in range(M):
    S, E, L = map(int, input().split())
    graph[S][E] = graph[E][S] = min(graph[E][S], L)
    fire[S][E] = fire[E][S] = max(fire[E][S], L)

for m in range(1, N + 1):
    for s in range(1, N + 1):
        for e in range(1, N + 1):
            graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e])

answer = INF
for s in range(1, N + 1):
    cand = 0
    for m in range(1, N + 1):
        for e in range(1, N + 1):
            if graph[m][e] == INF: continue
            remain = fire[m][e] - (graph[s][e] - graph[s][m])
            if remain: cand = max(cand, remain / 2 + graph[s][e])
    answer = min(answer, cand)

print(round(answer, 1))
