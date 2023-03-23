import sys
input = sys.stdin.readline

answer = []
N = int(input())
for _ in range(N):
    tasecase = input().strip()
    temp = []

    count = 0
    for i in range(len(tasecase)):
        if tasecase[i] == 'X':
            count = 0
        else:
            count += 1
            temp.append(count)

    answer.append(sum(temp))

for n in answer:
    print(n)
