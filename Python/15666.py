import sys

RESULT = []

def backtracking(cnt):
    if cnt == M:        
        for num in RESULT:
            print(num, end=' ')
        print()
        return

    for i in range(N):
        if len(RESULT) != 0 and RESULT[-1] > lst[i]:
            continue
        RESULT.append(lst[i])
        backtracking(cnt+1)
        RESULT.pop()

N, M = tuple(map(int, sys.stdin.readline().split()))
lst = list(map(int, sys.stdin.readline().split()))
lst = list(set(lst))
lst.sort()
N = len(lst)

backtracking(0)
