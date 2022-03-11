import sys

RESULT = []

def backtracking(cnt):
    if cnt == M:
        print(" ".join(RESULT))
        return

    prev_num = -1
    for i in range(N):
        if checking[i] == 0 and prev_num != lst[i]:
            RESULT[cnt] = str(lst[i])
            checking[i] = 1
            backtracking(cnt+1)
            prev_num = lst[i]
            checking[i] = 0

N, M = tuple(map(int, sys.stdin.readline().split()))
lst = list(map(int, sys.stdin.readline().split()))
lst.sort()
checking = [0] * 10001
RESULT = [-2] * M

backtracking(0)
