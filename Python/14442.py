# 백준 14442: 벽 부수고 이동하기 2(골드 III), https://www.acmicpc.net/problem/14442
import sys
from collections import deque
input = sys.stdin.readline

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < N and 0 <= y < M

def bfs(start):
    dq = deque()

    x = start[0]
    y = start[1]

    dq.append((x, y, 1, 0)) # x, y, dist, brokenCount
    visited[0][x][y] = True

    while dq:
        cx, cy, dist, brokenCount = dq.popleft()

        if cx == N-1 and cy == M-1:
            return dist
        
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny): continue
            
            if jido[nx][ny] == 0:
                if visited[brokenCount][nx][ny]: continue
                visited[brokenCount][nx][ny] = True
                dq.append((nx, ny, dist + 1, brokenCount))
            else:
                if brokenCount >= K: continue
                if visited[brokenCount + 1][nx][ny]: continue
                visited[brokenCount + 1][nx][ny] = True
                dq.append((nx, ny, dist + 1, brokenCount+1))
    return -1
                        
N, M, K = map(int, input().split())
jido = []
visited = [[[False for _ in range(M)] for _ in range(N)] for _ in range(K+1)]
for _ in range(N):
    jido.append(list(map(int, input().strip())))

print(bfs((0, 0)))
