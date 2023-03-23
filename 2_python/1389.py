# 백준 1389: 케빈 베이컨의 6단계 법칙(실버 I), https://www.acmicpc.net/problem/1389
import sys
input = sys.stdin.readline

INF = 10000000

N, M = map(int, input().split())
graph = [[INF for _ in range(N)] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

for m in range(N):
    for s in range(N):
        for e in range(N):
            graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e])

for i in range(N):
    graph[i][i] = 0

count = [0 for _ in range(N)]
for i in range(N):
    count[i] = sum(graph[i])

minCount = min(count)
print(count.index(minCount)+1)
