import sys, heapq
input = sys.stdin.readline

INF = int(1e9)

def dijkstra(start):
    dist = [INF] * (N + 1)

    hq = []
    heapq.heappush(hq, (0, start))
    dist[start] = 0

    while hq:
        w, cur = heapq.heappop(hq)

        if dist[cur] < w:
            continue

        for nw, nxt in graph[cur]:
            cost = w + nw

            if cost >= dist[nxt]:
                continue
            dist[nxt] = cost
            heapq.heappush(hq, (cost, nxt))
    
    return dist

N, E = map(int, input().split())
graph = [[] for _ in range(N + 1)]

for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
    graph[b].append((c, a))

v1, v2 = map(int, input().split())
dist1 = dijkstra(v1)
dist2 = dijkstra(v2)

answer = min(dist1[1] + dist1[v2] + dist2[N], dist2[1] + dist2[v1] + dist1[N])
print(answer if answer < INF else -1)