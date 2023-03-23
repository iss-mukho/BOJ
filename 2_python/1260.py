# 백준: DFS와 BFS(실버 II), https://www.acmicpc.net/problem/1260

import sys
from collections import deque
sys.setrecursionlimit(10000)

def dfs(v):
    print(v+1, end=' ')

    for next in graph[v]:
        if checked[next] == 0:
            checked[next] = 1
            dfs(next)

def bfs(v):
    dq = deque()
    dq.append(v)
    print(v+1, end=' ')

    while dq:
        cur = dq.popleft()

        for next in graph[cur]:
            if checked[next] == 0:
                checked[next] = 1
                dq.append(next)
                print(next+1, end=' ')
        
N, M, V = map(int, input().split())

graph = [[] for _ in range(N)] # 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다.
for _ in range(M):
    s, e = map(int, input().split())

    graph[s-1].append(e-1)
    graph[e-1].append(s-1) # 입력으로 주어지는 간선은 양방향이다.

# 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
for i in range(N):
    graph[i].sort()

checked = [0] * N
checked[V-1] = 1
dfs(V-1)
print()

checked = [0] * N
checked[V-1] = 1
bfs(V-1)
