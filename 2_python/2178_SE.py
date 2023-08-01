from collections import deque

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < N and 0 <= y < M

def BFS(start):
    dq = deque()
    dq.append(start)
    dist[start[0]][start[1]] = 1

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny): continue
            if graph[nx][ny] == '0': continue
            if dist[nx][ny] <= dist[cx][cy] + 1: continue

            dist[nx][ny] = dist[cx][cy] + 1
            dq.append((nx, ny))

N, M = map(int, input().split())
graph = []
for _ in range(N):
    graph.append(input())

dist = [[10001] * M for _ in range(N)]
BFS((0, 0))
print(dist[N-1][M-1])