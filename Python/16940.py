# 백준 16940: BFS 스페셜 저지(골드 III), https://www.acmicpc.net/problem/16940
# 대충 시간초과였는데 Pypy3이 살렸다는 자막
import sys
from collections import deque
input = sys.stdin.readline

def BFS(start):
    dq = deque()

    dq.append(start)
    visited[start] = True
    currentIndex = 1

    while dq:
        s = dq.popleft()
        
        # 큐에 있는 노드(1: 시작점)와, 그 노드에 연결된 노드들을 삽입한다.
        while True:
            if currentIndex == N: break
            temp = inputPath[currentIndex] # 이때, 입력 받은 순서대로 삽입을 시도한다.

            isConnected = False
            for n in graph[s]:
                if temp == n:
                    isConnected = True
                    break
            if not isConnected: break # 만약 현재 노드에서 "원하는 노드"가 연결이 되어있지 않다면 break함 -> 하단의 반복문에서 False를 반환

            # 연결된 간선 dq에 삽입
            dq.append(temp)
            visited[temp] = True
            currentIndex += 1

        # 이때 방문하지 않은 정점이 존재하면, 불가능한 BFS 연산
        for e in graph[s]:
            if visited[e]: continue
            return False
    return True

N = int(input())

graph = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]

for _ in range(N-1):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

inputPath = list(map(int, input().split()))

print(0 if inputPath[0] != 1 or not BFS(inputPath[0]) else 1)
