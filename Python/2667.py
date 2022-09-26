# 백준, 단지번호붙이기(실버 I), https://www.acmicpc.net/problem/2667

import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def in_range(x, y):
    return 0 <= x < N and 0 <= y < N

def DFS(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if in_range(nx, ny) and geo[nx][ny] == 1 and check[nx][ny] == 0:
            check[nx][ny] = 1
            answer[-1] += 1
            DFS(nx, ny)

answer = []
N = int(input())

geo = []
for _ in range(N):
    geo.append(list(map(int, input().strip())))
check = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    for j in range(N):
        if geo[i][j] == 1 and check[i][j] == 0:
            check[i][j] = 1
            answer.append(1)
            cnt = DFS(i, j)

answer.sort()
print(len(answer))
for n in answer:
    print(n)
