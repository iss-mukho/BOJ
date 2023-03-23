# 백준: 도시 분할 계획(골드 IV), https://www.acmicpc.net/problem/1647

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

N, M = map(int, input().split())
cities = [i for i in range(N)]
edges = []
for _ in range(M):
    A, B, C = map(int, input().split())
    edges.append((C, A-1, B-1))

edges.sort()

answer = 0
max_edge = 0 # 마을을 최소 유지비를 가지는 길들을 통해 2개로 분리해야 하므로, 크루스칼 알고리즘을 적용한 후 최대 유지비를 가지는 길을 없앤다.
for edge in edges:
    w, s, e = edge

    if find_parent(cities, s) != find_parent(cities, e):
        union_parent(cities, s, e)
        answer += w
        max_edge = w

print(answer - max_edge)
