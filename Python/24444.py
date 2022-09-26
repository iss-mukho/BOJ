# 백준, 알고리즘 수업 - 너비 우선 탐색 1(실버 II), https://www.acmicpc.net/problem/24444

import sys
from collections import deque
input = sys.stdin.readline

def bfs(start):
    global cnt
    dq = deque()

    cnt += 1
    visited[start] = cnt
    dq.append(start)

    while dq:
        cur = dq.popleft()

        graph[cur].sort()
        for end in graph[cur]:
            if visited[end] == 0:
                cnt += 1
                visited[end] = cnt
                dq.append(end)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N)]
visited = [0 for _ in range(N)]
cnt = 0

for _ in range(M):
    s, e = map(int, input().split())
    graph[s-1].append(e-1)
    graph[e-1].append(s-1)

bfs(R-1)

for i in range(N):
    print(visited[i])
