# 백준, 유기농 배추(실버 II), https://www.acmicpc.net/problem/1012

import sys
from collections import deque
input = sys.stdin.readline

def BFS(x, y):
    dq = deque()

    visited[x][y] = 1
    dq.append([x, y])

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if in_range(nx, ny) and geo[nx][ny] and visited[nx][ny] == 0:
                visited[nx][ny] = 1
                dq.append([nx, ny])

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def in_range(x, y):
    return 0 <= x < N and 0 <= y < M

T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())
    
    geo = [[0 for _ in range(M)] for _ in range(N)]
    visited = [[0 for _ in range(M)] for _ in range(N)]
    for _ in range(K):
        X, Y = map(int, input().split())
        geo[Y][X] = 1
    
    cnt = 0
    for i in range(N):
        for j in range(M):
            if geo[i][j] == 1 and visited[i][j] == 0:
                cnt += 1
                BFS(i, j)
    print(cnt)
    