import sys

def backtracking(cnt, n, m):
    if cnt == m:
        for x in output:
            print(x, end=' ')
        print()
        return

    for i in range(1, n+1):
        if checking[i] == 0:
            checking[i] = 1
            output.append(i)
            backtracking(cnt+1, n, m)
            checking[i] = 0
            output.pop()

N, M = tuple(map(int, sys.stdin.readline().split()))
checking = [0] * (N+1)
output = []

# 출력
backtracking(0, N, M)
