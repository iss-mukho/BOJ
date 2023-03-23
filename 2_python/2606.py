# 백준, 바이러스(실버 III), https://www.acmicpc.net/problem/2606

import sys
from collections import deque
input = sys.stdin.readline

def BFS(start):
    dq = deque()
    
    dq.append(start)
    visited[start] = 1

    while dq:
        cur = dq.popleft()

        for next in nodes[cur]:
            if visited[next] == 0:
                dq.append(next)
                visited[next] = 1

N = int(input())
M = int(input())

nodes = [[] for _ in range(N)]
visited = [0 for _ in range(N)]

for _ in range(M):
    start, end = map(int, input().split())
    nodes[start-1].append(end-1)
    nodes[end-1].append(start-1)

BFS(0)
print(sum(visited)-1)
