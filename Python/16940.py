# 백준 16940: BFS 스페셜 저지(골드 III)
import sys
from collections import deque
input = sys.stdin.readline

def BFS(start):
    dq = deque()
    dq.append(start)

    while dq:
        s = 


N = int(input())
graph = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]
for _ in range(N):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)
inputPath = list(map(int, input().split()))

