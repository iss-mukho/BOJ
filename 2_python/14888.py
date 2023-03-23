import sys

def backtracking(result, idx):
    if idx == N:
        global max_, min_

        if result > max_:
            max_ = result
        if min_ > result:
            min_ = result
        return

    for i in range(4):
        if operator[i] > 0:
            operator[i] -= 1
            if i == 0:
                backtracking(result + number[idx], idx+1)
            elif i == 1:
                backtracking(result - number[idx], idx+1)
            elif i == 2:
                backtracking(result * number[idx], idx+1)
            else:
                backtracking(int(result / number[idx]), idx+1)
            operator[i] += 1

N = int(sys.stdin.readline())
number = list(map(int, sys.stdin.readline().split()))
operator = list(map(int, sys.stdin.readline().split())) # +, -, *, /

max_ = -100000000000
min_ = 100000000000
backtracking(number[0], 1)

print(f"{max_}\n{min_}")
