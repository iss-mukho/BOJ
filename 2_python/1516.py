# 백준, 게임 개발(골 III), https://www.acmicpc.net/problem/1516

import sys
from collections import deque
input = sys.stdin.readline

def topology_sort():
    result = [0 for _ in range(N)]
    dq = deque()

    for i in range(N):
        if indegree[i] == 0:
            dq.append(i)

    while dq:
        cur = dq.popleft()
        result[cur] += times[cur]

        for g in graph[cur]:
            indegree[g] -= 1
            result[g] = max(result[g], result[cur])
            if indegree[g] == 0:
                dq.append(g)
    return result

N = int(input())
times = [0] * N
indegree = [0] * N
graph = [[] for _ in range(N)]
for i in range(N):
    temp = list(map(int, input().split()))
    times[i] = temp[0]
    for j in range(1, len(temp)-1):
        graph[temp[j]-1].append(i)
        indegree[i] += 1

times = topology_sort()
for time in times:
    print(time)
