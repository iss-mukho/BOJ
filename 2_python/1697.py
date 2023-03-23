# 백준, 숨바꼭질(실 I), https://www.acmicpc.net/problem/1697

from collections import deque

INF = int(1e9)

def in_range(x):
    return 0 <= x <= 100000

def bfs(start):
    dq = deque()
    graph[start] = 0
    dq.append(start)

    while dq:
        cur = dq.popleft()

        next_list = [cur-1, cur+1, cur*2]
        for next in next_list:
            if in_range(next) and graph[next] > graph[cur] + 1:
                graph[next] = graph[cur] + 1
                dq.append(next)
        
N, K = map(int, input().split())
graph = [INF for _ in range(100001)]

bfs(N)

print(graph[K])
