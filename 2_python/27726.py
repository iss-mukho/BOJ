# 백준 27726: 굉장한 모비스터디(골드 II), https://www.acmicpc.net/problem/27726
import sys
input = sys.stdin.readline

def findParent(x):
    if parent[x] != x:
        parent[x] = findParent(parent[x])
    return parent[x]

def unionParent(a, b):
    a = findParent(a)
    b = findParent(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N = int(input())
M = list(map(int, input().split()))

component = {}
for i in range(1, N + 1):
    component[i] = []

for m in M:
    parent = [i for i in range(N + 1)]
    for _ in range(m):
        a, b = map(int, input().split())
        if findParent(a) != findParent(b):
            unionParent(a, b)

    for i in range(1, N+1):
        component[i].append(findParent(i))
    parent.clear()

conv = sorted(component.items(), key = lambda d: d[1])
answer = []

i, j = 0, 1
temp = []
while i < j and j < N:
    if len(temp) == 0:
        temp.append(conv[i][0])
        continue

    if conv[i][1] == conv[j][1]:
        temp.append(conv[j][0])
    else:
        if len(temp) > 1:
            temp.sort()
            answer.append(temp[:])
        i = j
        temp.clear()
    j += 1
if len(temp) > 1:
    temp.sort()
    answer.append(temp[:])

answer.sort()
print(len(answer))
for ans in answer:
    print(*ans)
