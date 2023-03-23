''' 백준 16947: 서울 지하철 2호선(골드 III), https://www.acmicpc.net/problem/16947
- 순환선 확인: 깊이 우선 탐색
- 거리 확인: 너비 우선 탐색
'''
import sys
from collections import deque
sys.setrecursionlimit(100000)
input = sys.stdin.readline

INF = 100000000

def dfs(start, index, count):
    if(start == index and count >= 2):
        global isCycle
        isCycle = True
        return
    
    visited[index] = True
    for end in graph[index]:
        if not visited[end]:
            dfs(start, end, count + 1)
        elif start == end and count >= 2:
            dfs(start, end, count)

def bfs():
    dq = deque()
    
    for i in range(1, N+1):
        if cycleStation[i]:
            dist[i] = 0
            dq.append(i)
            visited[i] = True
    
    while dq:
        cur = dq.popleft()

        for next in graph[cur]:
            if cycleStation[next]: continue
            if dist[next] < dist[cur] + 1: continue
            
            dist[next] = dist[cur] + 1
            dq.append(next)
            visited[next] = True

N = int(input())
graph = [[] for _ in range(N+1)]
cycleStation = [False for _ in range(N+1)]
dist = [INF for _ in range(N+1)]

for _ in range(N):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N+1):
    visited = [False for _ in range(N+1)]
    isCycle = False
    dfs(i, i, 0)
    if isCycle:
        cycleStation[i] = True

bfs()

for i in range(1, N+1):
    print(dist[i], end=' ')
print()
