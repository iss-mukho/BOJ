import sys
from collections import deque

input = sys.stdin.readline

def getDist(x1, x2, y1, y2):
  return abs(x1 - x2) + abs(y1 - y2)

def isHappy(home, cvs, festival):
  hx, hy = home
  fx, fy = festival

  dq = deque()
  dq.append((hx, hy))

  cvsSize = len(cvs)
  visited = [False for _ in range(cvsSize)]

  while dq:
    cx, cy = dq.popleft()

    if getDist(cx, fx, cy, fy) <= 1000: return True

    for i in range(cvsSize):
      if visited[i] == True:
        continue
      
      nx, ny = cvs[i]

      if getDist(cx, nx, cy, ny) <= 1000:
        dq.append((nx, ny))
        visited[i] = True

  return False

for _ in range(int(input())):
  n = int(input())

  home = list(map(int, input().split()))

  cvs = []
  for _ in range(n):
    cvs.append(tuple(map(int, input().split())))
  
  festival = tuple(map(int, input().split()))

  print('happy' if isHappy(home, cvs, festival) == True else 'sad')
