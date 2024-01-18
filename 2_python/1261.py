import heapq

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def inRange(x, y):
    return 0 <= x < N and 0 <= y < M

def BFS():
    hq = []
    visited = [[False for _ in range(M)] for _ in range(N)]

    heapq.heappush(hq, (0, (0, 0)))
    visited[0][0] = True

    while hq:
        brokenCnt, xy = heapq.heappop(hq)
        x, y = xy
        
        if x == N - 1 and y == M - 1:
            return brokenCnt
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not inRange(nx, ny): continue
            if visited[nx][ny]: continue

            visited[nx][ny] = True
            heapq.heappush(hq, (brokenCnt + graph[nx][ny], (nx, ny)))

M, N = map(int, input().split())
graph = [list(map(int, input())) for _ in range(N)]
print(BFS())
