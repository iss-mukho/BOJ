# 백준, 상근이의 여행(실 IV), https://www.acmicpc.net/problem/9372

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    for _ in range(m):
        s, e = map(int, input().split())
    print(n-1)

'''
# 백준, 상근이의 여행(실 IV), https://www.acmicpc.net/problem/9372

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

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())

    parent = [i for i in range(n)]
    edges = []
    for _ in range(m):
        s, e = map(int, input().split())
        edges.append((s-1, e-1))
        edges.append((e-1, s-1))
    
    edges.sort()
    result = 0
    for edge in edges:
        s, e = edge
        if find_parent(parent, s) != find_parent(parent, e):
            union_parent(parent, s, e)
            result += 1
    print(result)

'''