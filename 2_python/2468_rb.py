from collections import deque

dx = [-1, +1, +0, +0]
dy = [+0 ,+0, -1, +1]

def inRange(x, y):
    return 0 <= x < N and 0 <= y < N

def bfs(x, y, h):
    dq = deque()
    dq.append((x, y))
    visited[x][y] = True

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]

            if not inRange(nx, ny): continue
            if visited[nx][ny]: continue
            if graph[nx][ny] <= h: continue
            
            dq.append((nx, ny))
            visited[nx][ny] = True

N = int(input())
answer = 1
graph = []

height = {'low': 101, 'high': 0}
for _ in range(N):
    row = list(map(int, input().split()))
    graph.append(row)

    height['low'] = min(min(row), height['low'])
    height['high'] = max(max(row), height['high'])

for h in range(height['low'], height['high']):
    visited = [[False for _ in range(N)] for _ in range(N)]

    cnt = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j]: continue
            if graph[i][j] <= h: continue
            cnt += 1
            bfs(i, j, h)
    
    answer = max(answer, cnt)

print(answer)
