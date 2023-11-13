import sys
sys.setrecursionlimit(100000)

def dfs(cur):
    global seq

    edges[cur].sort()
    visited[cur] = seq
    seq += 1
    
    for next in edges[cur]:
        if visited[next] != 0: continue
        dfs(next)

N, M, R = map(int, input().split())

edges = [[] for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]

for _ in range(M):
    u, v = map(int, input().split())
    edges[u].append(v)
    edges[v].append(u)

seq = 1
dfs(R)

for i in range(1, N + 1):
    print(visited[i])
