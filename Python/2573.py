# 백준 2573: 빙산(골드 IV), https://www.acmicpc.net/problem/2573
import sys
from collections import deque
input = sys.stdin.readline

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < N and 0 <= y < M

def melting():
    ice = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if graph[i][j]:
                cnt = 0
                for k in range(4):
                    ni, nj = i + dx[k], j + dy[k]
                    if inRange(ni, nj) and not graph[ni][nj]:
                        cnt += 1
                ice[i][j] = cnt
    for i in range(N):
        for j in range(M):
            graph[i][j] -= ice[i][j]
            if graph[i][j] < 0:
                graph[i][j] = 0

def bfs(x,y):
    dq = deque()
    dq.append((x, y))
    visited[x][y] = True

    while dq:
        cx, cy = dq.popleft()
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if inRange(nx, ny) and graph[nx][ny] and not visited[nx][ny]:
                dq.append((nx, ny))
                visited[nx][ny] = True

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

time = 0
while True:
    visited = [[False for _ in range(M)] for _ in range(N)]

    melting()
    cnt = 0
    check = 0
    time += 1
    for i in range(N):
        for j in range(M):
            if graph[i][j] and not visited[i][j]:
                bfs(i, j)
                cnt += 1
                check += 1

    if cnt > 1:
        print(time)
        break
    if not check:
        print(0)
        break
    