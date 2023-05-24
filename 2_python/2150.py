'''
백준 2150: Strongly Connected Component(플래티넘 V), https://www.acmicpc.net/problem/2150
타잔 알고리즘
    - 깊이 우선 탐색으로 방향 그래프의 정점 방문
    - 방문한 정점의 간선을 통해 상위에서 방문된 정점을 방문하는 경우 사이클 - S.C.C가 존재
'''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

def DFS(x):
    global idx
    idx += 1
    visited[x] = idx
    stack.append(x)

    result = visited[x]
    for i in range(len(graph[x])):
        y = graph[x][i]
        if visited[y] == 0: result = min(result, DFS(y))
        elif not isSCC[y]: result = min(result, visited[y])

    if result == visited[x]:
        scc = []
        while True:
            t = stack.pop()
            scc.append(t)
            isSCC[t] = True
            if t == x: break
        scc.sort()
        answer.append(scc[:])
    return result

V, E = map(int, input().split())
graph = [[] for _ in range(E + 1)]
visited = [0] * (E + 1)
isSCC = [False] * (E + 1)
stack = []
idx = 0
answer = []

for _ in range(E):
    A, B = map(int, input().split())
    graph[A].append(B)

for i in range(1, V):
    if visited[i] != 0: continue
    DFS(i)

answer.sort()
print(len(answer))
for ans in answer:
    print(*ans, end=' ')
    print("-1")
