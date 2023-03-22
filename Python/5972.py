# 백준 5972: 택배 배송(골드 V), https://www.acmicpc.net/problem/5972
import sys, heapq
input = sys.stdin.readline
INF = 1000000000

def dijkstra(start):
    hq = []
    heapq.heappush(hq, (0, start))

    while hq:
        w, s = heapq.heappop(hq)
        if dist[s] < w: continue

        for next in graph[s]:
            ew, e = next
            nw = w + ew
            if dist[e] > nw:
                dist[e] = nw
                heapq.heappush(hq, (nw, e))

N, M = map(int, input().split())
graph = [[] for _ in range(N+1)]
dist = [INF for _ in range(N+1)]
for _ in range(M):
    s, e, w = map(int, input().split())
    graph[s].append((w, e))
    graph[e].append((w, s))
    
dist[1] = 0
dijkstra(1)
print(dist[N])
