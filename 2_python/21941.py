import sys
sys.setrecursionlimit(10000)

S = list(input())
M = int(input())
ds = []
dp = [-1] * len(S)

def func(S, idx):
    if idx >= len(S):
        return 0
    
    if dp[idx] != -1:
        return dp[idx]
    
    dp[idx] = func(S, idx+1)+1

    for d in ds:
        X, A = d

        if S[idx:idx+len(A)] == A:
            dp[idx] = max(dp[idx], func(S, idx+len(A))+X)

    return dp[idx]

answer = 0
for _ in range(M):
    A, X = input().split()
    ds.append((int(X), list(A)))
ds.sort(reverse=True)

print(func(S, 0))
