answer = []
temp = []
def func(idx, cnt):
    if cnt == M:
        answer.append(temp[:])
        return
    
    for i in range(idx, N):
        temp.append(numbers[i])
        func(i, cnt + 1)
        temp.pop()

N, M = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()
func(0, 0)

before = []
for ans in sorted(answer):
    if before == ans:
        continue
    print(*ans)
    before = ans[:]