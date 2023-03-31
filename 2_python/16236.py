# 백준 16236: 아기 상어(골드 III), https://www.acmicpc.net/problem/16236
from collections import deque
import sys
input = sys.stdin.readline

INF = int(1e9)

# U, D, L, R
dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < N and 0 <= y < N

sharkSize = 2
upCount = 0
time = 0
start = []

def BFS(start, canGo):
    dq = deque()
    visited = [[INF for _ in range(N)] for _ in range(N)]
    
    visited[start[0]][start[1]] = 0
    dq.append([start[0], start[1], 0])
    while dq:
        cx, cy, cd = dq.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if not inRange(nx, ny): continue
            if visited[nx][ny] <= cd + 1: continue
            if area[nx][ny] > sharkSize: continue

            if area[nx][ny] > 0 and area[nx][ny] < sharkSize:
                canGo.append([nx, ny, cd+1])

            visited[nx][ny] = cd+1
            dq.append([nx, ny, cd+1])

N = int(input())
area = []
for i in range(N):
    area.append(list(map(int, input().split())))

    if len(start): continue
    for j in range(N):
        if area[i][j] == 9:
            start = [i, j]
            area[i][j] = 0
            break

while True:
    canGo = []
    BFS(start, canGo)
    if not len(canGo): break

    canGo.sort(key = lambda k:(k[2], k[0], k[1]))
    eatX, eatY, eatTime = canGo[0]
    upCount += 1

    if upCount == sharkSize:
        sharkSize += 1
        upCount = 0
    start = [eatX, eatY]
    area[eatX][eatY] = 0
    time += eatTime

print(time)

''' 기분 좋아서 안지우는 주석
simulation
1. 그래프탐색
    -1. 먹을 수 있는 것(작은 것)이 1개라면, 바로 이동
    -2. 먹을 수 있는 것이 여러 개라면, 가장 가까운 곳으로 이동한다.
        - 가장 가까운 곳이 여러 곳이라면, 가장 위, 가장 왼쪽으로 이동한다.
2. 이동 시 걸리는 시간은 1초, 섭취 시 걸리는 시간은 없음

area - ㅇㅋ? ㅇㅇ
BFS(start) - canGo에 넣음
canGo = (x, y, dist) - 같은 곳은 0이랑 같이 취급한다
정렬 lambda (dist, x, y)

빼먹었던 조건: 상어는 "본인의 크기만큼 물고기를 먹으면", 크기가 1 증가한다.
'''