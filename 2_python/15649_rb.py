result = []

def dfs(count, checked):
    if count == M:
        print(*result)
        return
    
    for i in range(N):
        if checked[i]: continue

        result.append(i + 1)
        checked[i] = True
        dfs(count + 1, checked)
        checked[i] = False
        result.pop()

N, M = map(int, input().split())

checked = [False for _ in range(N)]
dfs(0, checked)
