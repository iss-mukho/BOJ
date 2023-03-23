# 백준 파티(골드 III), https://www.acmicpc.net/problem/1238

import heapq
INF = int(1e9)

def dijkstra(start):
    hq = []
    dist = [INF for _ in range(N)]
    heapq.heappush(hq, (0, start))
    dist[start] = 0

    while hq:
        time, cur = heapq.heappop(hq)
        if dist[cur] < time:
            continue

        for next_list in graph[cur]:
            time_, next = next_list

            cost = time + time_
            if cost < dist[next]:
                dist[next] = cost
                heapq.heappush(hq, (cost, next))

    return dist

N, M, X = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    start, end, time = map(int, input().split())
    graph[start-1].append([time, end-1])

result = -1
for start in range(N):
    first_dist = dijkstra(start)
    second_dist = dijkstra(X-1)
    result = max(result, first_dist[X-1] + second_dist[start])

print(result)
