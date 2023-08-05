import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < N and 0 <= y < N

def check(isNo, cx, cy, nx, ny):
    if isNo:
        return graph[cx][cy] == graph[nx][ny]
    else:
        return graph[cx][cy] in ['R', 'G'] and graph[nx][ny] in ['R', 'G'] or graph[cx][cy] == graph[nx][ny]

def bfs(start, isNo):
    dq = deque()
    dq.append(start)
    visited[start[0]][start[1]] = True

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny):
                continue
            if visited[nx][ny]:
                continue
            if not check(isNo, cx, cy, nx, ny):
                continue
            
            dq.append((nx, ny))
            visited[nx][ny] = True

N = int(input())
graph = []
visited = [[False] * N for _ in range(N)]
for _ in range(N):
    graph.append(input().rstrip())

answer1 = 0
answer2 = 0

for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            bfs((i, j), True)
            answer1 += 1

visited = [[False] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            bfs((i, j), False)
            answer2 += 1

print(answer1, answer2)