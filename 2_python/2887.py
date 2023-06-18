# 백준 2887: 행성 터널(플래티넘 V), https://www.acmicpc.net/problem/2887
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

answer = 0

N = int(input())
parent = [i for i in range(N)]

location = []
for i in range(N):
    x, y, z = map(int, input().split())
    location.append([x, y, z, i])

edge = []
for dot in range(3):
    location.sort(key = lambda l: l[dot])
    before = location[0][3]
    for i in range(1, N):
        current = location[i][3]
        edge.append([before, current, abs(location[i][dot] - location[i - 1][dot])])
        before = current

edge.sort(key = lambda l: l[2])
for p1, p2, dist in edge:
    if findParent(p1) == findParent(p2): continue
    answer += dist
    unionParent(p1, p2)

print(answer)
