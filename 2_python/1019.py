# 백준: 책 페이지(골드 I), https://www.acmicpc.net/problem/1019
def calc(page, number, index):
    while page > 0:
        number[page % 10] += index
        page //= 10

N = int(input())
number = [0] * 10

start = 1
index = 1

while start <= N:
    while N % 10 != 9 and start <= N:
        calc(N, number, index)
        N -= 1
    
    if N < start: break

    while start % 10 != 0 and start <= N:
        calc(start, number, index)
        start += 1
    
    start //= 10
    N //= 10

    for i in range(10):
        number[i] += (N - start + 1) * index
    
    index *= 10

print(*number)
