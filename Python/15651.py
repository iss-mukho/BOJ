import sys

def backtracking(cnt, n, m):
    if cnt == m:
        for x in output:
            print(x, end=' ')
        print()
        return

    for i in range(1, n+1):
        if len(output) == 0 or i >= output[-1]:
            output.append(i)
            backtracking(cnt+1, n, m)
            output.pop()

N, M = tuple(map(int, sys.stdin.readline().split()))
output = []

# 출력
backtracking(0, N, M)
