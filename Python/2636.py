# 백준 2636: 치즈(골드 IV), https://www.acmicpc.net/problem/2636
import sys
from collections import deque
input = sys.stdin.readline

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < R and 0 <= y < C

def bfs(start):
    dq = deque()

    # 바깥 영역(공기) 확인
    dq.append(start)
    visited[start[0]][start[1]] = True

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny): continue
            if visited[nx][ny]: continue
            if cheese[nx][ny] == 1: continue

            dq.append([nx, ny])
            visited[nx][ny] = True

    # 치즈 처리
    for i in range(1, R-1):
        for j in range(1, C-1):
            if cheese[i][j] == 0: continue

            # 상하좌우 중 한 곳이라도 공기와 접촉하면 녹음
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                
                if visited[nx][ny]:
                    cheese[i][j] = 0
                    break

def getCheeseCount():
    cnt = 0
    for i in range(1, R-1):
        for j in range(1, C-1):
            if cheese[i][j] == 1:
                cnt += 1
    return cnt

R, C = map(int, input().split())
cheese = []
for _ in range(R):
    cheese.append(list(map(int, input().split())))

time = 0
cheeseCount = 0
while True:
    tempCheeseCount = getCheeseCount()
    if tempCheeseCount == 0: break

    cheeseCount = tempCheeseCount

    visited = [[False for _ in range(C)] for _ in range(R)]
    bfs([0, 0])
    time += 1

print(time)
print(cheeseCount)