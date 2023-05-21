# 백준 11438: LCA 2(플래티넘 V), https://www.acmicpc.net/problem/11438
import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline
MAX = 21

def DFS(start, dep):
    visited[start] = True
    depth[start] = dep

    for end in graph[start]:
        if visited[end]: continue
        parent[end][0] = start
        DFS(end, dep + 1)

def init():
    DFS(1, 0)

    for i in range(1, MAX):
        for j in range(1, N + 1):
            parent[j][i] = parent[parent[j][i - 1]][i - 1]

def LCA(start, end):
    if depth[start] > depth[end]:
        start, end = end, start

    for i in range(MAX - 1, -1, -1):
        if depth[end] - depth[start] >= 2 ** i:
            end = parent[end][i]
    
    if start == end:
        return start

    for i in range(MAX - 1, -1, -1):
        if parent[start][i] != parent[end][i]:
            start = parent[start][i]
            end = parent[end][i]

    return parent[start][0]

N = int(input())
parent = [[0 for _ in range(MAX)] for _ in range(N + 1)]
graph = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]
depth = [0 for _ in range(N + 1)]

for _ in range(N - 1):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

init()

M = int(input())
for _ in range(M):
    s, e = map(int, input().split())
    print(LCA(s, e))
