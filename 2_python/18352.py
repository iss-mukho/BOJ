# 백준: 특정 거리의 도시 찾기(실 II), https://www.acmicpc.net/problem/18352

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
        for next_ in graph[cur]:
            cost = weight + 1

            if dist[next_] > cost:
                dist[next_] = cost
                heapq.heappush(hq, (cost, next_))

N, M, K, X = map(int, input().split())

graph = [[] for _ in range(N)]
dist = [INF] * N
for _ in range(M):
    s, e = map(int, input().split())
    graph[s-1].append(e-1)

dist[X-1] = 0
dijkstra(X-1)

answer = []
for i in range(len(dist)):
    if dist[i] == K:
        answer.append(i+1)

if len(answer) == 0:
    print(-1)
else:
    for n in answer:
        print(n)
