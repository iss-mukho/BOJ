numbers = []
def func(num, cnt):
    if cnt == M:
        print(*numbers)
        return
    
    for i in range(num, N + 1):
        numbers.append(i)
        func(i, cnt + 1)
        numbers.pop()

N, M = map(int, input().split())

func(1, 0)
