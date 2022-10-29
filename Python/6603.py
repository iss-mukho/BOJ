# 백준, 로또(실II), https://www.acmicpc.net/problem/6603

import sys
input = sys.stdin.readline

result = []
def dfs(depth, idx):
    if depth == 6:
        for n in result:
            print(n, end=' ')
        print()
        return
    
    for i in range(idx, K):
        result.append(S[i])
        dfs(depth+1, i+1)
        result.pop()

while True:
    in_num = list(map(int, input().split()))
    if in_num[0] == 0:
        break
    
    K = in_num[0]
    S = in_num[1:]
    dfs(0, 0)
    print()
