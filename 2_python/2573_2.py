import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def inRange(x, y):
  return 0 <= x < N and 0 <= y < M

def melting():
  isMelted = [[False for _ in range(M)] for _ in range(N)]

  for i in range(N):
      for j in range(M):
        if isMelted[i][j] == True:
          continue
        if arr[i][j] == 0:
          continue
        
        meltCount = 0
        for k in range(4):
          ni = i + dx[k]
          nj = j + dy[k]

          if not inRange(ni, nj):
            continue
          if isMelted[ni][nj] == True:
            continue
          if arr[ni][nj] != 0:
            continue

          meltCount += 1
          
        arr[i][j] -= meltCount
        if arr[i][j] < 0: arr[i][j] = 0
        isMelted[i][j] = True

def search(visited, x, y):
  dq = deque()
  dq.append((x, y))
  visited[x][y] = True

  while dq:
    cx, cy = dq.popleft()

    for i in range(4):
      nx = cx + dx[i]
      ny = cy + dy[i]

      if not inRange(nx ,ny):
        continue
      if visited[nx][ny] == True:
        continue
      if arr[nx][ny] == 0:
        continue

      dq.append((nx, ny))
      visited[nx][ny] = True

def process():
  year = 1

  while True:
    melting()

    visited = [[False for _ in range(M)] for _ in range(N)]
    checkCount = 0
    
    for i in range(N):
      for j in range(M):
        if visited[i][j] == True:
          continue
        if arr[i][j] == 0:
          continue

        search(visited, i, j)
        checkCount += 1
  
        if checkCount == 2:
          return year

    if checkCount == 0:
      return 0
    year += 1

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
print(process())
