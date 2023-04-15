# 백준 10423: 전기가 부족해(골드 II), https://www.acmicpc.net/problem/10423
import sys, heapq
input = sys.stdin.readline
hq = []

N, M, K = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)

kList = map(int, input().split())
for k in kList:
    heapq.heappush(hq, (0, k))
for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append((w, v))
    graph[v].append((w, u))

# Prim
answer = 0
while hq:
    w, c = heapq.heappop(hq)
    if visited[c]:
        continue

    visited[c] = True
    answer += w

    for nw, n in graph[c]:
        if visited[n]:
            continue
        heapq.heappush(hq, (nw, n))

print(answer)
