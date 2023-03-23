# 백준, 여행 가자(골 VI), https://www.acmicpc.net/problem/1976

import sys
input = sys.stdin.readline

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N = int(input())
parent = [i for i in range(N)]

M = int(input())

graph = []
for _ in range(N):
    graph.append(list(map(int, input().split())))

for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            union_parent(parent, i, j)

route = list(map(int, input().split()))

start = parent[route[0]-1]
answer = 'YES'
for r in route:
    if start != parent[r-1]:
        answer = 'NO'
        break

print(answer)
