# 백준, 스도쿠(골 IV), https://www.acmicpc.net/problem/2580

import sys
input = sys.stdin.readline

def get_num(i, j):
    result = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    for x in range(9):
        if sdoku[i][x] in result:
            result.remove(sdoku[i][x])
        if sdoku[x][j] in result:
            result.remove(sdoku[x][j])

    i = (i//3)*3
    j = (j//3)*3
    for x in range(i, i+3):
        for y in range(j, j+3):
            if sdoku[x][y] in result:
                result.remove(sdoku[x][y])
    
    return result

def backtracking(cnt):
    if cnt == len(zero):
        for i in range(9):
            print(*sdoku[i])
        exit(0)

    i, j = zero[cnt]
    numbers = get_num(i, j)
    for number in numbers:
        sdoku[i][j] = number
        backtracking(cnt+1)
        sdoku[i][j] = 0

sdoku = []
for _ in range(9):
    sdoku.append(list(map(int, input().split())))

zero = []
for i in range(9):
    for j in range(9):
        if sdoku[i][j] == 0:
            zero.append((i, j))

backtracking(0)
