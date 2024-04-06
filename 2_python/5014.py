from collections import deque

def inRange(floor):
  return 1 <= floor <= F

def bfs():
  dq = deque()
  visited = [False for _ in range(F + 1)]

  dq.append((S, 0))
  visited[S] = True

  move = (U, -D)

  while dq:
    currentFloor, countOfClickBtn = dq.popleft()

    if currentFloor == G:
      return countOfClickBtn
    
    for i in range(2):
      if move[i] == 0:
        continue

      nextFloor = currentFloor + move[i]

      if inRange(nextFloor) == False:
        continue
      if visited[nextFloor] == True:
        continue

      dq.append((nextFloor, countOfClickBtn + 1))
      visited[nextFloor] = True

  return "use the stairs"

F, S, G, U, D = map(int, input().split())
print(bfs())
