# 백준, 촌수계산(실 II), https://www.acmicpc.net/problem/2644

import sys
from collections import deque
input = sys.stdin.readline

def bfs(start):
    dq = deque()

    visited[start] = 0
    dq.append(start)
    
    while dq:
        cur = dq.popleft()

        for next in graph[cur]:
            if visited[next] == -1:
                visited[next] = visited[cur] + 1
                dq.append(next)
                
n = int(input())
visited = [-1 for _ in range(n)]
start, end = map(int, input().split())
m = int(input())
graph = [[] for _ in range(n)]
for _ in range(m):
    s, e = map(int, input().split())
    graph[s-1].append(e-1)
    graph[e-1].append(s-1)

bfs(start-1)
print(visited[end-1])
