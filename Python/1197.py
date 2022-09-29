# 백준, 최소 스패닝 트리(골 IV), https://www.acmicpc.net/problem/1197

import sys
sys.setrecursionlimit(10000)
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

V, E = map(int, input().split())

parent = [i for i in range(V)]
edges = []
for _ in range(E):
    s, e, w = map(int, input().split())
    edges.append((w, s-1, e-1))

edges.sort()
result = 0
for edge in edges:
    w, s, e = edge
    if find_parent(parent, s) != find_parent(parent, e):
        union_parent(parent, s, e)
        result += w
print(result)
