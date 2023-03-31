# 백준 14940: 쉬운 최단거리(실버 I), https://www.acmicpc.net/problem/14940
import sys
from collections import deque
input = sys.stdin.readline
INF = 10000000

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < n and 0 <= y < m
start = [-1, -1]

def BFS(start):
    dq = deque()
    dq.append(start)
    answer[start[0]][start[1]] = 0
    visited[start[0]][start[1]] = True

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny): continue
            if visited[nx][ny]: continue
            if not graph[nx][ny]: continue

            dq.append([nx, ny])
            answer[nx][ny] = answer[cx][cy] + 1
            visited[nx][ny] = True

n, m = map(int, input().split())

answer = [[INF for _ in range(m)] for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]
graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))
    if start[0] != -1: continue
    for j in range(m):
        if graph[i][j] == 2:
            start = [i, j]
            break

BFS(start)

for i in range(n):
    for j in range(m):
        if answer[i][j] != INF:
            print(answer[i][j], end=' ')
            continue
        if graph[i][j]:
            print(-1, end=' ')
            continue
        print(0, end=' ')
    print()
