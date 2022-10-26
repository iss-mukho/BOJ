# 백준, 섬의 개수(실 II), https://www.acmicpc.net/problem/4963

import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(2500)

# U, D, L, R, UL, UR, DL, DR
dx = [-1, +1, +0, +0, -1, -1, +1, +1]
dy = [+0, +0, -1, +1, -1, +1, -1, +1]

def in_range(x, y):
    return 0 <= x < H and 0 <= y < W

def BFS(x, y):
    dq = deque()
    visited[x][y] = 1
    dq.append([x, y])

    while dq:
        cx, cy = dq.popleft()

        for i in range(8):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if in_range(nx, ny) and visited[nx][ny] == 0 and map_[nx][ny] == 1:
                visited[nx][ny] = 1
                BFS(nx, ny)

while True:
    answer = 0

    W, H = map(int, input().split())
    if W + H == 0:
        break

    map_ = []
    for _ in range(H):
        map_.append(list(map(int, input().split())))

    visited = [[0 for _ in range(W)] for _ in range(H)]
    for i in range(H):
        for j in range(W):
            if visited[i][j] == 0 and map_[i][j] == 1:
                answer += 1
                BFS(i, j)

    print(answer)
