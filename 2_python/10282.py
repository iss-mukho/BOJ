# 백준, 해킹(골 IV), https://www.acmicpc.net/problem/10282

import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start):
    hq = []
    heapq.heappush(hq, (0, start))

    while hq:
        weight, cur = heapq.heappop(hq)
        if dist[cur] < weight:
            continue

        for next_list in graph[cur]:
            weight_, next_ = next_list
            cost = weight + weight_

            if dist[next_] > cost:
                dist[next_] = cost
                heapq.heappush(hq, (cost, next_))

t = int(input())
for _ in range(t):
    n, d, c = map(int, input().split())
    graph = [[] for _ in range(n)]
    dist = [INF for _ in range(n)]

    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b-1].append((s, a-1))
    dist[c-1] = 0
    dijkstra(c-1)
    
    cnt = 0
    time = 0
    for d in dist:
        if d != INF:
            cnt += 1
            time = max(time, d)
    print(cnt, time)
