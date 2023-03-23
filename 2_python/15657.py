import sys

def backtracking(cnt):
    if cnt == M:
        output = " ".join(result)
        print(output)
        return

    for i in range(N):
        if int(result[cnt-1]) <= lst[i]: 
            result[cnt] = str(lst[i])
            backtracking(cnt+1)
            result[cnt] = 0

N, M = tuple(map(int, sys.stdin.readline().split()))
lst = list(map(int, sys.stdin.readline().split()))
lst.sort()
result = [0] * M

backtracking(0)
