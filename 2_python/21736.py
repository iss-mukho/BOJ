import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def inRange(x, y):
  return 0 <= x < N and 0 <= y < M

def dfs(x, y, visited):
  answer = 0
  dq = deque()

  dq.append((x, y))

  while dq:
    cx, cy = dq.popleft()

    if campus[cx][cy] == 'P':
      answer += 1
      
    for i in range(4):
      nx = cx + dx[i]
      ny = cy + dy[i]

      if not inRange(nx, ny):
        continue
      
      if visited[nx][ny]:
        continue

      if campus[nx][ny] == 'X':
        continue

      visited[nx][ny] = True
      dq.append((nx, ny))

  return answer

N, M = map(int, input().split())

sx, sy = -1, -1
campus = []
for i in range(N):
  line = input().strip()
  campus.append(line)

  if 'I' in line:
    sx, sy = i, line.index('I')

answer = 0
visited = [[False for _ in range(M)] for _ in range(N)]

visited[sx][sy] = True
answer = dfs(sx, sy, visited)
print(answer if answer else 'TT')
