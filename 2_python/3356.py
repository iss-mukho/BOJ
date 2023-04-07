# 백준 3356: 라디오 전송(플래티넘 IV), https://www.acmicpc.net/problem/3356
import sys
input = sys.stdin.readline
def KMP():
    i = 0
    for j in range(1, L):
        while i > 0 and S[i] != S[j]: i = table[i-1]
        if S[i] == S[j]:
            i += 1
            table[j] = i
L = int(input())
S = input().strip()
table = [0 for _ in range(L)]
KMP()
print(L - table[-1])