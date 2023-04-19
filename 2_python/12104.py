# 백준 12104: 순환 순열(플래티넘 V), 
import sys
input = sys.stdin.readline

def KMP(text, pattern):
    answer = 0
    failTable = [0] * len(pattern)

    j = 0
    for i in range(1, len(pattern)):
        while j>0 and pattern[i] != pattern[j]:
            j = failTable[j-1]
        if pattern[i] == pattern[j]:
            j += 1
            failTable[i] = j
    
    j = 0
    for i in range(len(text)-1):
        while j>0 and text[i] != pattern[j]:
            j = failTable[j-1]
        if text[i] == pattern[j]:
            j += 1
            if j == len(pattern):
                answer += 1
                j = failTable[j-1]
            
    return answer

A = input().strip()
B = input().strip()
print(KMP(B*2, A))
