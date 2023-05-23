# 백준 1019: 책 페이지(골드 I), https://www.acmicpc.net/problem/1019
def calc(page, number, index):
    while page > 0:
        number[page % 10] += index
        page //= 10

N = int(input())
number = [0] * 10
start = 1
index = 1

while start <= N:
    # 페이지 번호 일의 자리를 9로
    while N % 10 != 9 and start <= N:
        calc(N, number, index)
        N -= 1
    
    if N < start: break

    # 시작 번호의 일의 자리를 0으로
    while start % 10 != 0 and start <= N:
        calc(start, number, index)
        start += 1
    
    start //= 10
    N //= 10

    # 규칙성
    for i in range(10):
        number[i] += (N - start + 1) * index
    
    index *= 10

print(*number)
