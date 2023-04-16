# 백준 7575: 바이러스(플래티넘 V), https://www.acmicpc.net/problem/7575
import sys
input = sys.stdin.readline

def KMP(text, pattern):
    failTable = [0] * len(pattern)

    j = 0
    for i in range(1, len(pattern)):
        while j>0 and pattern[i] != pattern[j]:
            j = failTable[j-1]
        if pattern[i] == pattern[j]:
            j += 1
            failTable[i] = j

    j = 0
    for i in range(len(text)):
        while j>0 and text[i] != pattern[j]:
            j = failTable[j-1]
        if text[i] == pattern[j]:
            if j == K-1:
                return True
            j += 1
    return False

N, K = map(int, input().split())
M = []
for _ in range(N):
    i = int(input())
    M.append(list(map(int, input().split())))

isVirus = False
for i in range(len(M[0]) - K + 1):
    pattern = M[0][i:i + K]
    for j in range(1, N):
        text = M[j]

        isVirus = KMP(text, pattern)
        if not isVirus:
            isVirus = KMP(text[::-1], pattern)
        if not isVirus:
            break
        if j == N-1:
            isVirus = True
            break
    if isVirus:
        break

print('YES' if isVirus else 'NO')
