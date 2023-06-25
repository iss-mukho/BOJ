# 백준 10811: 바구니 뒤집기(브론즈 II), https://www.acmicpc.net/problem/10811
N, M = map(int, input().split())
basket = [i for i in range(1, N + 1)]
for _ in range(M):
    i, j = map(int, input().split())
    while i < j:
        basket[i - 1], basket[j - 1] = basket[j - 1], basket[i - 1]
        i += 1
        j -= 1
print(*basket)