# 백준 13913: 숨바꼭질 4(골드 IV), https://www.acmicpc.net/problem/13913
import sys
from collections import deque
input = sys.stdin.readline

MAX = 100001
visited = [MAX+1 for _ in range(MAX)]
path = [MAX+1 for _ in range(MAX)]

def bfs(start):
    dq = deque()
    dq.append(start)
    visited[start] = 0
    path[start] = -1

    while dq:
        X = dq.popleft()
        
        move = [X-1, X+1, X*2]
        for i in range(3):
            next = move[i]
            nextTime = visited[X] + 1

            if next < 0 or MAX <= next: continue
            if visited[next] <= nextTime: continue

            visited[next] = nextTime
            dq.append(next)
            path[next] = X

def getPath(K):
    answer = []
    
    x = K
    while True:
        answer.append(x)
        if path[x] == -1: break
        x = path[x]

    answer.reverse()
    return answer

N, K = map(int, input().split())
bfs(N)
print(visited[K])
for n in getPath(K):
    print(n, end=' ')
print()
