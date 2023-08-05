import sys
input = sys.stdin.readline

def bfs():
    answer = 0

    q = [1]
    visited[1] = True

    while q:
        cur = q.pop(0)

        for nxt in graph[cur]:
            if not visited[nxt]:
                q.append(nxt)
                visited[nxt] = True
                answer += 1

    return answer

N = int(input())
M = int(input())

graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

print(bfs())