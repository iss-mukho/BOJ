# 백준, 우주신과의 교감(골 III), https://www.acmicpc.net/problem/1774

import sys, math
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

def get_dist(a_list, b_list):
    ax, ay = a_list
    bx, by = b_list

    return math.sqrt( (ax-bx)**2 + (ay-by)**2 )

N, M = map(int, input().split())
parent = [i for i in range(N)]

dots = []
for _ in range(N):
    dots.append(list(map(int, input().split())))

default = []
for _ in range(M):
    default.append(list(map(int, input().split())))

for d in default:
    a = d[0] - 1
    b = d[1] - 1
    union_parent(parent, a, b)

edges = []
for i in range(N-1):
    for j in range(i+1, N):
        w = get_dist(dots[i], dots[j])
        edges.append((w, i, j))
edges.sort()

answer = 0
for edge in edges:
    w, s, e = edge

    if find_parent(parent, s) != find_parent(parent, e):
        union_parent(parent, s, e)
        answer += w

print('%.2f'%answer)
