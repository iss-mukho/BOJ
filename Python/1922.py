# 백준, 네트워크 연결(골 IV), https://www.acmicpc.net/problem/1922

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

answer = 0

N = int(input())
parent = [i for i in range(N)]

M = int(input())
edges = []
for _ in range(M):
    s, e, w = map(int, input().split())
    edges.append((w, s-1, e-1))
edges.sort()

for edge in edges:
    weight, start, end = edge
    if find_parent(parent, start) != find_parent(parent, end):
        union_parent(parent, start, end)
        answer += weight

print(answer)
