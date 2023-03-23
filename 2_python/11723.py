import sys
input = sys.stdin.readline

check = [0] * 20

M = int(input())
for _ in range(M):
    cmd = list(input().split())
    
    if len(cmd) == 2:
        o, x = cmd
        x = int(x)-1

        if o == 'add' and not check[x]:
            check[x] = 1
        elif o == 'remove' and check[x]:
            check[x] = 0
        elif o == 'check':
            print(1 if check[x] else 0)
        elif o == 'toggle':
            if check[x]:
                check[x] = 0
            else:
                check[x] = 1
    else:
        if cmd[0] == 'all':
            check = [1] * 20
        else:
            check = [0] * 20
