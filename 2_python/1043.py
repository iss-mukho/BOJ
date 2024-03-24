import sys

input = sys.stdin.readline

def find(x):
  if parent[x] != x:
    parent[x] = find(parent[x])
  return parent[x]

def union(a, b):
  a = find(a)
  b = find(b)

  if a < b:
    parent[b] = a
  else:
    parent[a] = b

N, M = map(int, input().split())
parent = [i for i in range(N + 1)]

trueGuys = list(map(int, input().split()))
if trueGuys[0] != 0:
  trueGuys = trueGuys[1:]

  for guy in trueGuys:
    parent[guy] = 0

parties = []
for _ in range(M):
  party = list(map(int, input().split()))[1:]
  parties.append(party)

  for i in range(1, len(party)):
    union(party[0], party[i])

answer = M
for party in parties:
  for p in party:
    if find(parent[p]) == 0:
      answer -= 1
      break

print(answer)
