import sys

RESULT = []

def backtracking(cnt):
    if cnt == M:
        for x in RESULT:
            print(x, end=' ')
        print()
        return

    for idx in range(N):
        RESULT.append(lst[idx])
        backtracking(cnt+1)
        RESULT.pop()

N, M = tuple(map(int, sys.stdin.readline().split()))
lst = list(map(int, sys.stdin.readline().split()))
lst.sort()

backtracking(0)
