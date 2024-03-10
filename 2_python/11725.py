import sys
from collections import deque

input = sys.stdin.readline

def setParents():
  dq = deque()

  dq.append(1)
  checked[1] = True

  while dq:
    c = dq.popleft()

    for n in tree[c]:
      if checked[n]:
         continue

      parents[n] = c
      checked[n] = True
      dq.append(n)

N = int(input())

parents = [i for i in range(N + 1)]
checked = [False for _ in range(N + 1)]
tree = [[] for _ in range(N + 1)]

for _ in range(N - 1):
  a, b = map(int, input().split())
  tree[a].append(b)
  tree[b].append(a)

setParents()

for i in range(2, N + 1):
  print(parents[i])
