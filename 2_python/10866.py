import sys
from collections import deque

input = sys.stdin.readline

dq = deque()
for _ in range(int(input())):
  line = input()

  first = line[0]
  if first == 'p':
    if line[1] == 'u':
      lineList = line.split()
      X = int(lineList[1])

      if line[5] == 'f':
        dq.appendleft(X)
      else:
        dq.append(X)
    else:
      if line[4] == 'f':
        print(-1 if not len(dq) else dq.popleft())
      else:
        print(-1 if not len(dq) else dq.pop())
  elif first == 's':
    print(len(dq))
  elif first == 'e':
    print(0 if len(dq) else 1)
  elif first == 'f':
    print(dq[0] if len(dq) else -1)
  else:
    print(dq[-1] if len(dq) else -1)
