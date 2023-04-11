# 백준 11048: 이동하기(실버 II), https://www.acmicpc.net/problem/11048
import sys
input = sys.stdin.readline

dx = [-1, +0, -1]
dy = [+0, -1, -1]
def inRange(r, c):
    return 0 <= r < N and 0 <= c < M

N, M = map(int, input().split())
maze = []
for _ in range(N):
    maze.append(list(map(int, input().split())))

dp = [[0 for _ in range(M)] for _ in range(N)]
dp[0][0] = maze[0][0]

for i in range(N):
    for j in range(M):
        for k in range(3):
            bi = i + dx[k]
            bj = j + dy[k]

            if(not inRange(bi, bj)): continue
            dp[i][j] = max(dp[i][j], dp[bi][bj] + maze[i][j])

print(dp[N-1][M-1])
