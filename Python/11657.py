# 백준 11657: 타임머신(골드 IV), https://www.acmicpc.net/problem/11657
import sys
input = sys.stdin.readline

INF = 30000000001
MAX = 500

edges = []
dist = [INF for _ in range(MAX + 1)]

def ballmanFord(start):
    global N

    dist[start] = 0
    for i in range(1, N+1):
        for edge in edges:
            s, e, w = edge

            if dist[s] != INF and dist[e] > dist[s] + w:
                dist[e] = dist[s] + w
                
                if i == N:
                    return False
    return True

N, M = map(int, input().split())

for _ in range(M):
    A, B, C = map(int, input().split())
    edges.append([A, B, C])

if not ballmanFord(1):
    print(-1)
else:
    for i in range(2, N+1):
        if dist[i] == INF:
            print(-1)
        else:
            print(dist[i])