# 분할정복
def star(lst, n, x, y):
    if n == 1:
        lst[x][y] = '*'
    else:
        a = int(n / 3)
        star(lst, a, x, y) # (1, 1)
        star(lst, a, x, y + a) # (1, 2)
        star(lst, a, x, y + a * 2) # (1, 3)
        star(lst, a, x + a, y) # (2, 1)
        # (2, 2), 이곳이 공백이어야 함
        star(lst, a, x + a, y + a * 2) # (2, 3)
        star(lst, a, x + a * 2, y) # (3, 1)
        star(lst, a, x + a * 2, y + a) # (3, 2)
        star(lst, a, x + a * 2, y + a * 2) # (3, 3)

graph = [
    [' ' for _ in range(2188)]
    for _ in range(2188)
]

N = int(input())
star(graph, N, 1, 1)
for i in range(1, N+1):
    for j in range(1, N+1):
        print(graph[i][j], end='')
    print()