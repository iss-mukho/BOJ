# 백준, 특정한 최단 경로(골 Iv), https://www.acmicpc.net/problem/1504

import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start):
    dist = [INF for _ in range(N)]
    dist[start] = 0

    hq = []
    heapq.heappush(hq, (0, start))

    while hq:
        w, cur = heapq.heappop(hq)

        if dist[cur] < w:
            continue
        for w_, end in graph[cur]:
            cost = w + w_
            if dist[end] > cost:
                dist[end] = cost
                heapq.heappush(hq, (cost, end))
    return dist

N, E = map(int, input().split())
graph = [[] for _ in range(N)]

for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a-1].append((c, b-1))
    graph[b-1].append((c, a-1))

v1, v2 = map(int, input().split())
v1 -= 1
v2 -= 1

dist0 = dijkstra(0)
dist1 = dijkstra(v1)
dist2 = dijkstra(v2)
case = min(dist0[v1] + dist1[v2] + dist2[N-1], dist0[v2] + dist2[v1] + dist1[N-1])

print(case if case < INF else -1)
