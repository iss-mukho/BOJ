import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, +1, +0, +0, +0, +0]
dy = [+0, +0, -1, +1, +0, +0]
dz = [+0, +0, +0, +0, -1, +1]

def inRange(x, y, z):
  return 0 <= x < N and 0 <= y < M and 0 <= z < H

def getStartList():
  startList = []

  for z in range(H):
    for x in range(N):
      for y in range(M):
        if graph[z][x][y] == 1:
          startList.append((x, y, z))

  return startList

def getMaxTime(startList):
  maxTime = 1
  dq = deque()

  for start in startList:
    dq.append(start)

  while dq:
    cx, cy, cz = dq.popleft()

    for i in range(6):
      nx = cx + dx[i]
      ny = cy + dy[i]
      nz = cz + dz[i]

      if not inRange(nx, ny, nz):
        continue

      if graph[nz][nx][ny] != 0:
        continue

      nextTime = graph[cz][cx][cy] + 1
      graph[nz][nx][ny] = nextTime
      dq.append((nx, ny, nz))

      maxTime = max(maxTime, nextTime)

  return maxTime - 1

def getAnswer(maxTime):
  for z in range(H):
    for x in range(N):
      for y in range(M):
        if graph[z][x][y] == 0:
          return -1

  return maxTime

M, N, H = map(int, input().split())
graph = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]

startList = getStartList()
maxTime = getMaxTime(startList)
print(getAnswer(maxTime))
