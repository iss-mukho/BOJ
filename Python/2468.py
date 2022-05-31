'''
백준 2468번: 안전 영역(Silver I)
개념: 그래프 이론/탐색, 브루트포스, DFS, BFS
https://www.acmicpc.net/problem/2468
'''

import sys
from queue import Queue
sys.setrecursionlimit(10000)

# U, D, L, R
dx = [+0, +0, -1, +1]
dy = [-1, +1, +0, +0]

def in_range(x, y):
    return 0 <= x and x < N and 0 <= y and y < N

def DFS(x, y, n):
    # move
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if in_range(nx, ny) and visited[nx][ny] == 0 and local[nx][ny] > n:
            # check
            visited[nx][ny] = 1
            DFS(nx, ny, n)


def BFS(x, y, n):
    q = Queue()
    q.put([x, y])

    while not q.empty():
        cx, cy = q.get()
        # move
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if in_range(nx, ny) and visited[nx][ny] == 0 and local[nx][ny] > n:
                # check
                visited[nx][ny] = 1
                q.put([nx, ny])

answer = 1
N = int(input())

in_min = 101
in_max = 0
local = []
for _ in range(N):
    in_row = list(map(int, input().split()))
    local.append(in_row)

    in_min = min(min(in_row), in_min)
    in_max = max(max(in_row), in_max)

for n in range(in_min, in_max):
    visited = [
        [0 for _ in range(N)]
        for _ in range(N)
    ]
    
    cnt = 0
    for i in range(N):
        for j in range(N):
            if local[i][j] > n and visited[i][j] == 0:
                visited[i][j] = 1
                cnt += 1
                #DFS(i, j, n)
                BFS(i, j, n)
    answer = max(answer, cnt)

print(answer)
