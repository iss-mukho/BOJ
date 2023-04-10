# 백준 2206: 벽 부수고 이동하기(골드 III), https://www.acmicpc.net/problem/2206
import sys
from collections import deque
input = sys.stdin.readline

INF = int(1e9)

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < N and 0 <= y < M

def BFS():
    dq = deque()
    dist[0][0][0] = 1
    dq.append([0, 0])

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny): continue

            if graph[nx][ny] == 0:
                if dist[cx][cy][0] + 1 < dist[nx][ny][0]:
                    dist[nx][ny][0] = dist[cx][cy][0] + 1
                    dq.append([nx, ny])
                if dist[cx][cy][1] + 1 < dist[nx][ny][1]:
                    dist[nx][ny][1] = dist[cx][cy][1] + 1
                    dq.append([nx, ny])
            else:
                if dist[cx][cy][0] + 1 < dist[nx][ny][1]:
                    dist[nx][ny][1] = dist[cx][cy][0] + 1
                    dq.append([nx, ny])

N, M = map(int, input().split())
graph = []
dist = [[[INF for _ in range(2)] for _ in range(M)] for _ in range(N)]
for _ in range(N):
    graph.append(list(map(int, input().strip())))

BFS()
answer = min(dist[N-1][M-1])

print(answer if answer != INF else -1)
