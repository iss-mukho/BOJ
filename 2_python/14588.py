import sys
input = sys.stdin.readline

INF = int(1e9)
N = int(input())

lines = []
for _ in range(N):
    left, right = list(map(int, input().split()))
    lines.append([left, right])

answer = [[INF for _ in range(N)] for _ in range(N)]
for i in range(N):
    answer[i][i] = 0

for i in range(N):
    for j in range(i+1, N):
        if lines[j][0] <= lines[i][1] and lines[i][0] <= lines[j][1]:
            answer[i][j] = 1
            answer[j][i] = 1  # 양방향 간선

# 플로이드 워셜
for mid in range(N):
    for start in range(N):
        for end in range(N):
            answer[start][end] = min(answer[start][end], answer[start][mid] + answer[mid][end])

Q = int(input())
for _ in range(Q):
    a, b = map(int, input().split())
    print(-1 if answer[a-1][b-1] == INF else answer[a-1][b-1])
