# 백준 5430: AC(골드 V), https://www.acmicpc.net/problem/5430
import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    p = list(input().strip())
    n = int(input())
    x = input().strip()
    dq = deque()
    if n: dq = deque(x[1:len(x)-1].split(','))

    isError = False
    isBack = True
    for c in p:
        if c == 'R':
            isBack = not isBack
            continue
        
        if not dq:
            isError = True
            break

        if isBack:
            dq.popleft()
        else:
            dq.pop()
    
    if isError:
        print('error')
        continue

    if isBack:
        print('['+','.join(dq)+']')
    else:
        print('['+','.join(list(dq)[::-1])+']')
