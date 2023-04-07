# 백준 4354: 문자열 제곱(플래티넘 V), https://www.acmicpc.net/problem/4354
import sys
input = sys.stdin.readline

def KMP(pattern, L):
    fail = [0 for _ in range(L)]
    i = 0
    for j in range(1, L):
        while i > 0 and pattern[i] != pattern[j]:
            i = fail[i-1]
        if pattern[i] == pattern[j]:
            i += 1
            fail[j] = i
    return fail

while True:
    pattern = input().strip()
    if pattern == '.': break
    L = len(pattern)
    fail = KMP(pattern, L)
    print(L // (L - fail[L-1]) if (L % (L - fail[L-1])) == 0 else 1)
