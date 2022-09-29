# 백준, 주유소(실 III), https://www.acmicpc.net/problem/13305

answer = 0
n = int(input())
dist = list(map(int, input().split()))
cost = list(map(int, input().split()))

oil = cost[0]
for i in range(n-1):
    if oil > cost[i]:
        oil = cost[i]
    answer += (dist[i] * oil)

print(answer)
