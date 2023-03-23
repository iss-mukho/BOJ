import sys
input = sys.stdin.readline

N = int(input())
P = list(map(int, input().split()))
P.sort()

if N > 1:
    for i in range(1, N):
        P[i] += P[i-1]
print(sum(P))