# 백준 10810: 공 넣기(브론즈 III), https://www.acmicpc.net/problem/10810
N, M = map(int, input().split())

basket = [0] * (N)
for _ in range(M):
    i, j, k = map(int, input().split())
    for idx in range(i, j + 1):
        basket[idx - 1] = k

print(*basket)