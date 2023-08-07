answer = []
def func(cnt):
    if cnt == M:
        print(*answer)
        return
    
    for i in range(N):
        if used[i]:
            continue
        used[i] = True
        answer.append(numbers[i])
        func(cnt + 1)
        used[i] = False
        answer.pop()

N, M = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()
used = [False] * (N)
func(0)
