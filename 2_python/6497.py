import sys

input = sys.stdin.readline

def findParent(x):
  if parent[x] != x:
    parent[x] = findParent(parent[x])
  
  return parent[x]

def unionParent(a, b):
  a, b = findParent(a), findParent(b)

  if a < b:
    parent[b] = a
  else:
    parent[a] = b

while True:
  m, n = map(int, input().split())

  if m == 0 and n == 0:
    break

  nodes = []
  parent = [i for i in range(m)]

  for _ in range(n):
    x, y, z = map(int, input().split())
    nodes.append((z, (x, y)))

  nodes.sort()

  answer = 0
  for z, node in nodes:
    x, y = node

    if findParent(x) != findParent(y):
      unionParent(x, y)
    else:
      answer += z

  print(answer)
