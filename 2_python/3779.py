# 백준 3779: 주기(플래티넘 IV), https://www.acmicpc.net/problem/3779
import sys
input = sys.stdin.readline

def KMP(pattern):
    failTable = [0] * len(pattern)

    j = 0
    for i in range(1, len(pattern)):
        while j>0 and pattern[i] != pattern[j]:
            j = failTable[j-1]
        if pattern[i] == pattern[j]:
            j += 1
            failTable[i] = j

        a = failTable[i]
        b = (i+1) - failTable[i]

        if a % b:
            continue
        if a // b > 0:
            print("{} {}".format(i+1, a//b+1))

t = 1
while True:
    N = int(input())
    if N == 0:
        break
    S = input().strip()
    
    print("Test case #{}".format(t))
    KMP(S)
    print()

    t += 1
