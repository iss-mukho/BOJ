# 백준 13424: 비밀 모임(골드 IV), https://www.acmicpc.net/problem/13424
import sys
input = sys.stdin.readline

INF = 100000000

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())

    secret = [[INF for _ in range(N)] for _ in range(N)]
    for _ in range(M):
        s, e, w = map(int, input().split())
        secret[s-1][e-1] = w
        secret[e-1][s-1] = w
    
    K = int(input())
    friend = list(map(int, input().split()))

    for i in range(N):
        secret[i][i] = 0

    for m in range(N):
        for s in range(N):
            for e in range(N):
                secret[s][e] = min(secret[s][e], secret[s][m] + secret[m][e])
    
    result = [0 for _ in range(N)]
    for f in friend:
        for i in range(N):
            result[i] += secret[f-1][i]
    print(result.index(min(result)) + 1)
    