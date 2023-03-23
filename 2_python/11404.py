# 백준, 플로이드(골 IV), https://www.acmicpc.net/problem/11404

import sys
input = sys.stdin.readline
INF = int(1e9)

n = int(input())
graph = [[INF for _ in range(n)] for _ in range(n)]
for i in range(n):
    graph[i][i] = 0

m = int(input())
for _ in range(m):
    a, b, c = map(int, input().split())
    if graph[a-1][b-1] > c: # 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
        graph[a-1][b-1] = c

for m in range(n):
    for s in range(n):
        for e in range(n):
            graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e])
    
for i in range(n):
    for j in range(n):
        print(graph[i][j] if graph[i][j] != INF else 0, end=' ')
    print()
