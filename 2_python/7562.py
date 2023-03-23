# 백준, 나이트의 이동(실 I), https://www.acmicpc.net/problem/7562

import sys
from collections import deque
input = sys.stdin.readline

INF = int(1e9)

def in_range(x, y):
    return 0 <= x < l and 0 <= y < l

dx = [-2, -2, -1, -1, +1, +1, +2, +2]
dy = [-1, +1, -2, +2, -2, +2, -1, +1]

def bfs(start):
    dq = deque()

    graph[start[0]][start[1]] = 0
    dq.append(start)

    while dq:
        cx, cy = dq.popleft()
        if next_list == [cx, cy]:
            break

        for i in range(8):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if in_range(nx, ny) and graph[nx][ny] > graph[cx][cy] + 1:
                graph[nx][ny] = graph[cx][cy] + 1
                dq.append([nx, ny])

t = int(input())
for _ in range(t):
    l = int(input())
    graph = [[INF for _ in range(l)] for _ in range(l)]
    cur_list = list(map(int, input().split()))
    next_list = list(map(int, input().split()))

    bfs(cur_list)

    print(graph[next_list[0]][next_list[1]])
