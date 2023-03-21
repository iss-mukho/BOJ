# 백준 2407: 조합(실버 III), https://www.acmicpc.net/problem/2407
N, M = map(int, input().split())

a = 1
b = 1
for i in range(N, N-M, -1):
    a *= i
for i in range(M, 0, -1):
    b *= i

print(a//b)