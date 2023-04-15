# 백준 1865: 웜홀(골드 III), https://www.acmicpc.net/problem/1865
import sys
input = sys.stdin.readline
INF = 3000000000

def ballmanFord():
	dist = [INF] * (N+1)
	for i in range(1, N+1):
		for edge in edges:
			s, e, w = edge
			if dist[s] + w >= dist[e]: continue
			dist[e] = dist[s] + w
			if i == N:
				return False
	return True

T = int(input())
for _ in range(T):
	N, M, W = map(int, input().split())
	edges = []

	for _ in range(M):
		S, E, T = list(map(int, input().split()))
		edges.append([S, E, T])
		edges.append([E, S, T])
	for _ in range(W):
		S, E, T = list(map(int, input().split()))
		edges.append([S, E, -T])

	print('YES' if not ballmanFord() else 'NO')
