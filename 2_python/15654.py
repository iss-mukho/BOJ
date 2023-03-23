import sys

RESULT = []

def backtracking(idx):
    if len(RESULT) == M:
        for x in RESULT:
            print(x, end=' ')
        print()
        return

    for i in range(N):
        if lst[i] not in RESULT:
            RESULT.append(lst[i])
            backtracking(idx+1)
            RESULT.pop()

N, M = tuple(map(int, sys.stdin.readline().split()))
lst = list(map(int, sys.stdin.readline().split()))
lst.sort()

backtracking(0)
