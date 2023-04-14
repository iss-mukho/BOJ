# 백준 1789: 수들의 합(실버 V), https://www.acmicpc.net/problem/1789
S = int(input())
temp = 1
N = 2
while temp < S:
    temp += N
    if temp > S: break
    N += 1
print(N-1)
