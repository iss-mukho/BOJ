# 백준 11585: 속타는 저녁 메뉴(플래티넘 V), https://www.acmicpc.net/problem/11585
import sys
input = sys.stdin.readline

def gcd(a, b):
    return a if b != 0 else gcd(b, a%b)

def KMP():
    cnt = 0

    j = 0
    for i in range(1, N):
        while j>0 and pattern[i] != pattern[j]:
            j = failTable[j-1]
        if pattern[i] == pattern[j]:
            j += 1
            failTable[i] = j

    j = 0
    for i in range(N*2-1):
        while j>0 and text[i] != pattern[j]:
            j = failTable[j-1]
        if text[i] == pattern[j]:
            if j == N-1:
                cnt += 1
                j = failTable[j]
                continue
            j += 1

    return cnt

N = int(input().strip())

failTable = [0 for _ in range(N)]
text = list(map(str, input().split())) * 2
pattern = list(map(str, input().split()))

A = KMP()
g = gcd(A, N)

print("{}/{}".format(A//g, N//g))
