# 백준 10816: 숫자 카드 2(실버 IV), https://www.acmicpc.net/problem/10816
import sys
input = sys.stdin.readline

MAX = 10000000
count = [0 for _ in range(MAX * 2 + 1)]

N = int(input())
numbers = list(map(int, input().split()))
for number in numbers:
    count[number+MAX] += 1

M = int(input())
answer = list(map(int, input().split()))

for a in answer:
    print(count[a+MAX], end=' ')
print()
