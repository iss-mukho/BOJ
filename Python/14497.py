# 백준 14497: 주난의 난(골드 IV), https://www.acmicpc.net/problem/14497
import sys
from collections import deque

input = sys.stdin.readline

# U, D, L, R
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
def inRange(x, y):
    return 0 <= x < N and 0 <= y < M

def bfs(start):
    dq = deque()
    dq.append(start)
    visited[start[0]][start[1]] = 0

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny): continue
            if visited[nx][ny] != -1: continue

            if graph[nx][ny] == "1" or graph[nx][ny] == "#":
                visited[nx][ny] = visited[cx][cy] + 1
                dq.append((nx, ny))
            elif graph[nx][ny] == "0":
                visited[nx][ny] = visited[cx][cy]
                dq.appendleft([nx, ny])

N, M = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
graph = []
for _ in range(N):
    graph.append(list(map(str, input().rstrip())))
visited = [[-1 for _ in range(M)] for _ in range(N)]

bfs([x1-1, y1-1])
print(visited[x2-1][y2-1])
