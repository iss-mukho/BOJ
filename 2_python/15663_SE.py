answer = []
temp = []
def func(cnt):
    if cnt == M:
        answer.append(temp[:])
        return
    
    for i in range(N):
        if used[i]:
            continue
        used[i] = True
        temp.append(numbers[i])
        func(cnt + 1)
        used[i] = False
        temp.pop()

N, M = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()
used = [False] * (N)
func(0)

before = []
for ans in sorted(answer):
    if before == ans:
        continue
    print(*ans)
    before = ans[:]