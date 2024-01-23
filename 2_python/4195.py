import sys

input = sys.stdin.readline
MAX = 200000

def findParent(parent, x):
  if x != parent[x]:
    parent[x] = findParent(parent, parent[x])

  return parent[x]

def unionParent(parent, a, b, children):
  a = findParent(parent, a)
  b = findParent(parent, b)

  if a < b:
    parent[b] = a
    children[a] += children[b]
  else:
    parent[a] = b
    children[b] += children[a]

def friendProcess(friendDict, friendCnt, id):
  if id not in friendDict:
    friendDict[id] = friendCnt
    friendCnt += 1

  return friendCnt

for _ in range(int(input())):
  parent = [x for x in range(MAX)]
  children = [1 for _ in range(MAX)]
  friendDict, friendCnt = {}, 0

  for _ in range(int(input())):
    a, b = input().split()

    friendCnt = friendProcess(friendDict, friendCnt, a)
    friendCnt = friendProcess(friendDict, friendCnt, b)

    aIdx, bIdx = friendDict[a], friendDict[b]
    if findParent(parent, aIdx) != findParent(parent, bIdx):
      unionParent(parent, aIdx, bIdx, children)

    aParent = findParent(parent, aIdx)
    print(children[aParent])
