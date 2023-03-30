# 백준 11054: 가장 긴 바이토닉 부분 수열(골드 IV), https://www.acmicpc.net/problem/11054
import sys
input = sys.stdin.readline

A = int(input())
numbers = list(map(int, input().split()))
reverseNumbers = numbers[::-1]

up = [1] * A
down = [1] * A
 
for i in range(A):
    for j in range(i):
        if numbers[i] > numbers[j]:
            up[i] = max(up[i], up[j] + 1)
        if reverseNumbers[i] > reverseNumbers[j]:
            down[i] = max(down[i], down[j] + 1)

answer = 0
for i in range(A):
    answer = max(answer, up[i] + down[A-i-1] - 1)
print(answer)
