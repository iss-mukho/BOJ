# 백준, 연결 요소의 개수(실 II), https://www.acmicpc.net/problem/11724

from collections import deque
import sys
input = sys.stdin.readline

def bfs(start):
    dq = deque()
    visited[start] = 1
    dq.append(start)

    while dq:
        next = dq.popleft()
        for n in graph[next]:
            if visited[n] == 0:
                visited[n] = 1
                dq.append(n)

N, M = map(int, input().split())
visited = [0 for _ in range(N)]
graph = [[] for _ in range(N)]
for _ in range(M):
    s, e = map(int, input().split())
    graph[s-1].append(e-1)
    graph[e-1].append(s-1)

answer = 0
for i in range(N):
    if visited[i] == 0:
        answer += 1
        bfs(i)

print(answer)
