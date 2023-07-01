# 백준 11060: 점프 점프(실버 II), https://www.acmicpc.net/problem/11060
from collections import deque

INF = 1001


def BFS():
    dq = deque()
    dq.append(0)

    while dq:
        now = dq.popleft()

        for step in range(1, graph[now] + 1):
            next = now + step
            if next >= N:
                continue
            if graph[next] == 0:
                continue

            if dp[next] <= dp[now] + 1:
                continue
            dp[next] = dp[now] + 1
            dq.append(next)


N = int(input())
graph = list(map(int, input().split()))

dp = [INF] * N
dp[0] = 0

BFS()
print(-1 if dp[-1] == INF else dp[-1])
