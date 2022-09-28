# 백준, 미로 탐색(실버 I), https://www.acmicpc.net/problem/2178

import sys
from collections import deque
input = sys.stdin.readline

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def in_range(x, y):
    return 0 <= x < N and 0 <= y < M

def bfs(x, y):
    dq = deque()
    visited[x][y] = 1
    dq.append((x, y))

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if in_range(nx, ny) and graph[nx][ny] == 1 and visited[nx][ny] == 0:
                visited[nx][ny] = visited[cx][cy] + 1
                dq.append((nx, ny))

N, M = map(int, input().split())
graph = []
for _ in range(N):
    graph.append(list(map(int, input().strip())))

visited = [[0 for _ in range(M)] for _ in range(N)]
bfs(0, 0)

print(visited[N-1][M-1])
