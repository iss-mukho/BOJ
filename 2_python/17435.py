# 백준 17435: 합성함수와 쿼리(골드 I), https://www.acmicpc.net/problem/17435
import sys, math
input = sys.stdin.readline
f = [[0 for _ in range(200001)] for _ in range(20)]

m = int(input())
fLine = list(map(int, input().split()))
for i in range(1, m + 1):
    f[0][i] = fLine[i - 1]

l = math.ceil(math.log2(500000))
for i in range(l):
    for j in range(1, m + 1):
        f[i + 1][j] = f[i][f[i][j]]

Q = int(input())
for _ in range(Q):
    n, x = map(int, input().split())

    i = 0
    while n != 0:
        if n % 2 == 1: x = f[i][x]
        n >>= 1
        i += 1

    print(x)
