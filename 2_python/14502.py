# 백준, 연구소(골 IV), https://www.acmicpc.net/problem/14502

from collections import deque
import sys, copy
input = sys.stdin.readline

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def in_range(x, y):
    return 0 <= x < N and 0 <= y < M

def set_wall(cnt):
    if cnt == 3:
        return bfs()
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 0:
                graph[i][j] = 1
                set_wall(cnt+1)
                graph[i][j] = 0

def bfs():
    global answer
    custom = copy.deepcopy(graph)
    dq = deque()

    for i in range(N):
        for j in range(M):
            if custom[i][j] == 2:
                dq.append([i, j])
    while dq:
        cx, cy = dq.popleft()
        
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if in_range(nx, ny) and custom[nx][ny] == 0:
                custom[nx][ny] = 2
                dq.append([nx, ny])
    answer = max(answer, count_zero(custom))

def count_zero(custom):
    result = 0
    for i in range(N):
        for j in range(M):
            if custom[i][j] == 0:
                result += 1
    return result

answer = 0
N, M = map(int, input().split())
graph = []
for _ in range(N):
    graph.append(list(map(int, input().split())))
set_wall(0)
print(answer)
