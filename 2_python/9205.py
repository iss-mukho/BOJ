# 백준 9205: 맥주 마시면서 걸어가기(골드 V), https://www.acmicpc.net/problem/9205
import sys
from collections import deque
input = sys.stdin.readline

def getDist(cx, cy, nx, ny):
    return abs(nx-cx) + abs(ny-cy)

def BFS():
    dq = deque()
    visited = [False for _ in range(N)]
    dq.append(start)

    while dq:
        cx, cy = dq.popleft()
        if getDist(cx, cy, end[0], end[1]) <= 1000:
            return True
        
        for i in range(N):
            if visited[i]:
                continue
            if getDist(cx, cy, CVS[i][0], CVS[i][1]) <= 1000:
                visited[i] = True
                dq.append(CVS[i])
    
    return False

T = int(input())
for _ in range(T):
    N = int(input())
    CVS = []

    start = list(map(int, input().split()))
    for _ in range(N):
        CVS.append(list(map(int, input().split())))
    end = list(map(int, input().split()))
    
    print("happy" if BFS() else "sad")
