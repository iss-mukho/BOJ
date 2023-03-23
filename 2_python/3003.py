# 백준 3003: 킹, 퀸, 룩, 비숍, 나이트, 폰(브론즈 V), https://www.acmicpc.net/problem/3003
import sys
input = sys.stdin.readline

baseList = [1, 1, 2, 2, 2, 8]
inputList = list(map(int, input().split()))

for i in range(6):
    print(baseList[i] - inputList[i], end=' ')
print()
