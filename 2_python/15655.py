import sys

def backtracking(idx):
    if sum(checking) == M:
        for i in range(10000):
            if checking[i] == 1:
                print(i+1, end=' ')
        print()
        return

    for i in range(idx, N):
        number = numbers[i]
        checking[number-1] = 1
        backtracking(i+1)
        checking[number-1] = 0

N, M = tuple(map(int, sys.stdin.readline().split()))
numbers = list(map(int, sys.stdin.readline().split()))
numbers.sort()
checking = [0] * 10000

backtracking(0)
