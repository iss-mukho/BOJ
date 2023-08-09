dx = [-1, +1, +0, +0]
dy = [+0, +0, -1, +1]

def inRange(x, y):
    return 0 <= x < R and 0 <= y < C

def getIndex(alphabet):
    return ord(alphabet) - 65

def dfs(x, y, cnt):
    global answer
    answer = max(answer, cnt)

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if not inRange(nx, ny):
            continue

        nIdx = getIndex(board[nx][ny])
        if visited[nIdx]:
            continue

        visited[nIdx] = True
        dfs(nx, ny, cnt + 1)
        visited[nIdx] = False

R, C = map(int, input().split())
board = [list(input()) for _ in range(R)]
visited = [False] * 26

answer = 0
visited[getIndex(board[0][0])] = True
dfs(0, 0, 1)
print(answer)
