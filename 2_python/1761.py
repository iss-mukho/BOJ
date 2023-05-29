# 백준 1761: 정점들의 거리(플래티넘 V), https://www.acmicpc.net/problem/1761
import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
HEIGHT = 20

depth = [0] * (40001)
parent = [[0 for _ in range(HEIGHT)] for _ in range(40001)]
dist = [[0 for _ in range(HEIGHT)] for _ in range(40001)]
adj = [[] for _ in range(40001)]

def findParent(p, n, d, c):
    depth[n] = d
    parent[n][0] = p
    dist[n][0] = c

    for next in adj[n]:
        if next[0] == p: continue
        findParent(n, next[0], d + 1, next[1])

def getDist(a, b):
    ans = 0

    if depth[a] != depth[b]:
        if depth[a] < depth[b]:
            a, b = b, a

        diff = depth[a] - depth[b]
        i = 0
        while 0 < diff:
            if diff % 2 == 1:
                ans += dist[a][i]
                a = parent[a][i]
            diff //= 2
            i += 1

    if a != b:
        for i in range(HEIGHT - 1, -1, -1):
            if parent[a][i] == 0 or parent[a][i] == parent[b][i]: continue
            ans += dist[a][i] + dist[b][i]
            a = parent[a][i]
            b = parent[b][i]
        ans += dist[a][0] + dist[b][0]

    return ans

N = int(input())

for _ in range(N - 1):
    a, b, c = map(int, input().split())
    adj[a].append([b, c])
    adj[b].append([a, c])

findParent(0, 1, 0, 0)

for i in range(1, HEIGHT):
    for j in range(2, N + 1):
        if parent[j][i - 1] == 0: continue
        parent[j][i] = parent[parent[j][i - 1]][i - 1]
        dist[j][i] = dist[j][i - 1] + dist[parent[j][i - 1]][i - 1]

M = int(input())
for _ in range(M):
    a, b = map(int, input().split())
    print(getDist(a, b))
