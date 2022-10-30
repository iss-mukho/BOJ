# 백준, 제로(실 IV), https://www.acmicpc.net/problem/10773

import sys
input = sys.stdin.readline

K = int(input())
numbers = []
for _ in range(K):
    number = int(input())
    if number:
        numbers.append(number)
    else:
        numbers.pop()
print(sum(numbers))
