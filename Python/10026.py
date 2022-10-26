# 백준, 적록색약(골 V), https://www.acmicpc.net/problem/10026

import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

answer = 0
answer2 = 0

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def in_range(x, y):
    return 0 <= x < N and 0 <= y < N

def DFS(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if in_range(nx, ny) and visited[nx][ny] == 0 and picture[nx][ny] == picture[x][y]:
            visited[nx][ny] = 1
            DFS(nx, ny)

def DFS2(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if in_range(nx, ny) and visited[nx][ny] == 0:
            if (picture[x][y] == 'B' and picture[x][y] == picture[nx][ny]) or (picture[x][y] != 'B' and picture[nx][ny] != 'B'):
                visited[nx][ny] = 1
                DFS2(nx, ny)

N = int(input())
picture = []
for _ in range(N):
    picture.append(list(input().strip()))

visited = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    for j in range(N):
        if visited[i][j] == 0:
            answer += 1
            visited[i][j] = 1
            DFS(i, j)

visited = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    for j in range(N):
        if visited[i][j] == 0:
            answer2 += 1
            visited[i][j] = 1
            DFS2(i, j)

print(answer, answer2)
