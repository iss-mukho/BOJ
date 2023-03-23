# 백준 2583: 영역 구하기(실버 I), https://www.acmicpc.net/problem/2583
import sys
from collections import deque
input = sys.stdin.readline

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < M and 0 <= y < N

def bfs(start):
    ans = 0

    dq = deque()
    dq.append(start)
    visited[start[0]][start[1]] = True

    while dq:
        cx, cy = dq.popleft()
        ans += 1

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny): continue
            if visited[nx][ny]: continue
            if graph[nx][ny] == 1: continue

            visited[nx][ny] = True
            dq.append((nx, ny))

    return ans

M, N, K = map(int, input().split())

graph = [[0 for _ in range(N)] for _ in range(M)]
visited = [[False for _ in range(N)] for _ in range(M)]
for _ in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            graph[i][j] = 1

answer = []
for i in range(M):
    for j in range(N):
        if visited[i][j]: continue
        if graph[i][j] == 1: continue

        answer.append(bfs((i, j)))

answer.sort()
print(len(answer))
for ans in answer:
    print(ans, end=' ')
print()
