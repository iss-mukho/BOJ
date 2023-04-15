# 백준 10266: 시계 사진들(플래티넘 IV), https://www.acmicpc.net/problem/10266
import sys
input = sys.stdin.readline
MAX = 360000

def KMP(text, pattern):
    j = 0
    for i in range(1, MAX):
        while j>0 and pattern[j] != pattern[i]:
            j = failTable[j-1]
        if pattern[i] == pattern[j]:
            j += 1
            failTable[i] = j

    j = 0
    for i in range(MAX*2):
        while j>0 and text[i] != pattern[j]:
            j = failTable[j-1]
        if text[i] == pattern[j]:
            if j == MAX-1:
                return 'possible'
            j += 1
    return 'impossible'

n = int(input())
T = list(map(int, input().split()))
P = list(map(int, input().split()))

text = [0] * (MAX*2)
pattern = [0] * MAX
failTable = [0] * MAX

for i in range(n):
    text[T[i]] = text[T[i]+MAX] = 1
    pattern[P[i]] = 1

print(KMP(text, pattern))
