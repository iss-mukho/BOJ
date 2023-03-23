# 백준, 선수과목 (Prerequisite)(골 V), https://www.acmicpc.net/problem/14567

import sys
input = sys.stdin.readline
from collections import deque

def topology_sort():
    result = [0 for _ in range(N)]
    dq = deque()

    for i in range(N):
        if indegree[i] == 0:
            dq.append((i, 1))
    
    while dq:
        cur, cnt = dq.popleft()
        result[cur] = cnt

        for subject in subjects[cur]:
            indegree[subject] -= 1

            if indegree[subject] == 0:
                dq.append((subject, cnt+1))
    
    return result

N, M = map(int, input().split())
indegree = [0 for _ in range(N)]

subjects = [[] for _ in range(N)]
for _ in range(M):
    A, B = map(int, input().split())
    subjects[A-1].append(B-1)
    indegree[B-1] += 1

result = topology_sort()
for n in result:
    print(n, end=' ')
print()
