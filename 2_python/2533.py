# 백준 2533: 사회망 서비스(SNS)(골드 III), https://www.acmicpc.net/problem/2533
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

# Bottom-Up
def find(node):
    visited[node] = True

    dp[node][0] = 1
    for child in graph[node]:
        if visited[child]: continue
        find(child)
        # 부모 노드가 얼리 어답터인 경우
        dp[node][0] += min(dp[child]) # 자식 노드가 얼리 어답터일 경우와 아닐 경우 중 더 작은 값
        # 부모 노드가 일반인인 경우
        dp[node][1] += dp[child][0] # 자식 노드가 모두 얼리 어답터여야 함

N = int(input())
graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)
for _ in range(N-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

dp = [[0, 0] for _ in range(N+1)] # [얼리 어답터, 일반인]
'''
본인 노드 + 해당 노드의 모든 자식 노드 중 조건을 만족하는 최소 얼리 어답터 수
[0]: 해당 노드가 얼리 어답터일 경우
[1]: 해당 노드가 일반인일 경우 
'''
find(1)
print(min(dp[1]))
