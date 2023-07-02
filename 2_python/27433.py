# 백준 27433: 팩토리얼 2(브론즈 V), https://www.acmicpc.net/problem/27433
n = 1
for i in range(1, int(input()) + 1):
    n *= i
print(n)
