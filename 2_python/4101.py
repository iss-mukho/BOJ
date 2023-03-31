# 백준 4101: 크냐?(브론즈 V), https://www.acmicpc.net/problem/4101
while True:
    a, b = map(int, input().split())
    if a>b: print('Yes')
    elif a==b:
        if a==0: break
        else: print('No')
    else: print('No')