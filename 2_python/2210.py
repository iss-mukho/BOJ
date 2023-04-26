# 백준 2210: 숫자판 점프(실버 II), https://www.acmicpc.net/problem/2210
import sys
input = sys.stdin.readline

dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]
def inRange(x, y):
    return 0 <= x < 5 and 0 <= y < 5

def DFS(x, y, depth, ans):
    if depth == 5:
        s.add(ans)
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if not inRange(nx, ny):
            continue
        DFS(nx, ny, depth + 1, ans + str(graph[nx][ny]))

s = set()
graph = []
for _ in range(5):
    graph.append(list(map(int, input().split())))

for i in range(5):
    for j in range(5):
        DFS(i, j, 0, str(graph[i][j]))
print(len(s))
