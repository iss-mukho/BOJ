# 백준 16947: 서울 지하철 2호선(골드 III), https://www.acmicpc.net/problem/16947
import sys
input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N)]

for _ in range(N):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

