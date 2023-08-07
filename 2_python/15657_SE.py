answer = []
def func(idx, cnt):
    if cnt == M:
        print(*answer)
        return
    
    for i in range(idx, N):
        answer.append(numbers[i])
        func(i, cnt + 1)
        answer.pop()

N, M = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()
func(0, 0)
