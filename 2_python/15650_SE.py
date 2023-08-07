numbers = []
def func(num, cnt):
    if cnt == M:
        print(*numbers)
        return
    
    for i in range(num, N + 1):
        if used[i]:
            continue
        used[i] = True
        numbers.append(i)
        func(i, cnt + 1)
        used[i] = False
        numbers.pop()

N, M = map(int, input().split())
used = [False] * (N + 1)

func(1, 0)
