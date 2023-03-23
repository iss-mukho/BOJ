import sys

def backtracking(cnt):
    if cnt == M:
        for x in result:
            print(x, end=' ')
        print()
        return

    before = -1
    for idx in range(cnt, N):
        if lst[idx] >= max(result) and checking[idx] == 0 and before != lst[idx]:
            result[cnt] = lst[idx]
            checking[idx] = 1
            before = lst[idx]
            backtracking(cnt+1)
            result[cnt] = 0
            checking[idx] = 0

N, M = tuple(map(int, sys.stdin.readline().split()))
lst = list(map(int, sys.stdin.readline().split()))
lst.sort()

checking = [0] * N
result = [0] * M

backtracking(0)
