import sys

RESULT = []

def backtracking(cnt):
    if cnt == M:        
        print(' '.join(RESULT))
        return

    for i in range(N):
        RESULT.append(str(lst[i]))
        backtracking(cnt+1)
        RESULT.pop()

N, M = tuple(map(int, sys.stdin.readline().split()))
lst = list(map(int, sys.stdin.readline().split()))
lst = list(set(lst))
lst.sort()
N = len(lst)

backtracking(0)
