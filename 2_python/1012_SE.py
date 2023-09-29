from collections import deque

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def inRange(x, y, N, M):
    return 0 <= x < N and 0 <= y < M

def process(field, N, M):
    count = 0

    for i in range(N):
        for j in range(M):
            if not field[i][j]: continue
            field[i][j] = 0
            bfs(field, N, M, i, j)
            count += 1
    
    return count

def bfs(field, N, M, x, y):
    dq = deque()
    dq.append((x, y))

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny, N, M): continue
            if not field[nx][ny]: continue

            field[nx][ny] = 0
            dq.append((nx, ny))

for _ in range(int(input())):
    M, N, K = map(int, input().split())
    field = [[0 for _ in range(M)] for _ in range(N)]

    for _ in range(K):
        X, Y = map(int, input().split())
        field[Y][X] = 1
    
    print(process(field, N, M))
