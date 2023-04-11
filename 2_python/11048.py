# 백준 11048: 이동하기(실버 II), https://www.acmicpc.net/problem/11048
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
maze = [[0] * (M+1)]
for _ in range(N):
    maze.append([0] + list(map(int, input().split())))

for i in range(1, N+1):
    for j in range(1, M+1):
        maze[i][j] += max(maze[i-1][j], maze[i-1][j-1], maze[i][j-1])

print(maze[N][M])
