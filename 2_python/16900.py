# 백준 16900: 이름 정하기(플래티넘 V), https://www.acmicpc.net/problem/16900
import sys
input = sys.stdin.readline

def failFunction(pattern):
    table = [0 for _ in range(len(S))]

    j = 0
    for i in range(1, len(pattern)):
        while j > 0 and pattern[i] != pattern[j]:
            j = table[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
            table[i] = j
    
    return table

S, K = input().split()
K = int(K)

table = failFunction(S)

sLen = len(S)
answer = sLen
for i in range(1, K):
    answer += sLen - table[sLen - 1]

print(answer)
