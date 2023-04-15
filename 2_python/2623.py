# 백준 2623: 음악프로그램(골드 III), https://www.acmicpc.net/problem/2623
import sys
from collections import deque
input = sys.stdin.readline

answer = []
def topologySort(graph, indegree):
    dq = deque()

    for i in range(1, N+1):
        if indegree[i] == 0:
            dq.append(i)
    
    if len(dq) == 0:
        return print(0)
    while dq:
        cur = dq.popleft()
        answer.append(cur)

        for next in graph[cur]:
            indegree[next] -= 1
            if(indegree[next] == 0):
                dq.append(next)

N, M = map(int, input().split())
graph = [[] for _ in range(N+1)]
indegree = [0 for _ in range(N+1)]
for _ in range(M):
    order = list(map(int, input().split()))
    for i in range(2, len(order)):
        graph[order[i-1]].append(order[i])
        indegree[order[i]] += 1

topologySort(graph, indegree)

if len(answer) != N:
    print(0)
else:
    for n in answer:
        print(n)
