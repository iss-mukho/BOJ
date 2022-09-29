# 백준, 줄 세우기(골 III), https://www.acmicpc.net/problem/2252

import sys
from collections import deque
input = sys.stdin.readline

def topology_sort():
    result = []
    dq = deque()

    for i in range(N):
        if indegree[i] == 0:
            dq.append(i)

    while dq:
        start = dq.popleft()
        result.append(start)

        for end in students[start]:
            indegree[end] -= 1
            if indegree[end] == 0:
                dq.append(end)
    return result

N, M = map(int, input().split())
students = [[] for _ in range(N)]
indegree = [0 for _ in range(N)]

for _ in range(M):
    start, end = map(int, input().split())
    students[start-1].append(end-1)
    indegree[end-1] += 1

result = topology_sort()
for r in result:
    print(r+1, end=' ')
