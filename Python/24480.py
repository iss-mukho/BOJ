# 백준, 알고리즘 수업 - 깊이 우선 탐색 2(실버 II), https://www.acmicpc.net/problem/24480

import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

def dfs(start):
    global cnt
    graph[start].sort(reverse=True)

    for end in graph[start]:
        if visited[end] == 0:
            cnt += 1
            visited[end] = cnt
            dfs(end)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N)]
visited = [0 for _ in range(N)]
cnt = 1

for _ in range(M):
    s, e = map(int, input().split())
    graph[s-1].append(e-1)
    graph[e-1].append(s-1)

visited[R-1] = cnt
dfs(R-1)

for i in range(N):
    print(visited[i])
