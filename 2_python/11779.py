# 백준: 최소비용 구하기 2(골 III), https://www.acmicpc.net/problem/11779

import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(s):
    hq = []
    heapq.heappush(hq, (0, s))

    while hq:
        weight, start = heapq.heappop(hq)

        if dist[start] < weight:
            continue

        for endList in businfo[start]:
            weight_, end = endList

            cost = weight + weight_
            if dist[end] > cost:
                path[end] = start
                dist[end] = cost
                heapq.heappush(hq, (cost, end))

def printAnswer(end):
    print(dist[end])

    temp_path = []
    getPath(temp_path, end)
    temp_path.reverse()

    print(len(temp_path))
    for i in temp_path:
        print(i+1, end=' ')
    print()

def getPath(temp_path, cur):
    temp_path.append(cur)
    if path[cur] == -1:
        return
    return getPath(temp_path, path[cur])
    
n = int(input())
m = int(input())

businfo = [[] for _ in range(n)]
for _ in range(m):
    start, end, weight = map(int, input().split())
    businfo[start-1].append((weight, end-1))

dist = [INF for _ in range(n)]
path = [-1 for _ in range(n)]
start, end = map(int, input().split())
dist[start-1] = 0
dijkstra(start-1)
printAnswer(end-1)
