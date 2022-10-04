# 백준, 도서관(골 V), https://www.acmicpc.net/problem/1461

N, M = map(int, input().split())
books = list(map(int, input().split()))

minus = []
plus = []
for n in books:
    if n < 0:
        minus.append(-n)
    else:
        plus.append(n)

minus.sort(reverse=True)
plus.sort(reverse=True)

answer = []
for i in range(len(plus) // M):
    answer.append(plus[i*M])
if len(plus) % M != 0:
    answer.append(plus[len(plus)//M*M])
for i in range(len(minus) // M):
    answer.append(minus[i*M])
if len(minus) % M != 0:
    answer.append(minus[len(minus)//M*M])
answer.sort()

print(answer.pop() + sum(answer)*2)
