# 백준: 녹색 옷 입은 애가 젤다지?(골 IV), https://www.acmicpc.net/problem/4485

import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

# U, D, L, R
dx = [+0, +0, -1, +1]
dy = [-1, +1, +0, +0]
def in_range(x, y):
    return 0 <= x < N and 0 <= y < N

def dijkstra():
    hq = []
    heapq.heappush(hq, (graph[0][0], (0, 0)))

    while hq:
        weight, cur = heapq.heappop(hq)
        cx, cy = cur

        if dist[cx][cy] < weight:
            continue

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not in_range(nx, ny):
                continue

            weight_ = graph[nx][ny]
            cost = weight + weight_

            if dist[nx][ny] > cost:
                dist[nx][ny] = cost
                heapq.heappush(hq, (cost, (nx, ny))) 

num = 1
while True:
    N = int(input())
    if N == 0:
        break

    graph = []
    for _ in range(N):
        graph.append(list(map(int, input().split())))
    dist = [[INF for _ in range(N)] for _ in range(N)]
    dist[0][0] = graph[0][0]
    dijkstra()

    print("Problem " + str(num) + ": " + str(dist[N-1][N-1]))
    num += 1
