# 백준, 숨바꼭질 3(골 V), https://www.acmicpc.net/problem/13549

import heapq

INF = int(1e9)

def in_range(x):
    return 0 <= x <= 100000

def dijkstra(start):
    hq = []
    graph[start] = 0
    heapq.heappush(hq, (0, start))

    while hq:
        w, cur = heapq.heappop(hq)

        if graph[cur] < w:
            continue

        next_list = [(1, cur-1), (1, cur+1), (0, cur*2)]
        for next in next_list:
            w_, n = next
            cost = w + w_
            if in_range(n) and graph[n] > cost:
                graph[n] = cost
                heapq.heappush(hq, (cost, n))
        
N, K = map(int, input().split())
graph = [INF for _ in range(100001)]

dijkstra(N)

print(graph[K])
