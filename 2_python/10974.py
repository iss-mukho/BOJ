import sys
input = sys.stdin.readline

check = [0] * 9
output = [0] * 8

def backtracking(n, cnt):
    if n == cnt:
        for i in range(cnt):
            print(output[i], end=' ')
        print()
        return

    for i in range(1, n+1):
        if check[i] == 1:
            continue

        output[cnt] = i
        check[i] = 1
        backtracking(n, cnt+1)
        output[cnt] = 0
        check[i] = 0

N = int(input())
backtracking(N, 0)
