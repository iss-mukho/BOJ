# 백준 10828: 스택(실버 IV), https://www.acmicpc.net/problem/10828
import sys
input = sys.stdin.readline
stack = []

N = int(input())
for _ in range(N):
    commands = list(map(str, input().split()))
    
    command = commands[0]
    
    if command == 'push':
        stack.append(commands[1])
    elif command == 'pop':
        if len(stack):
            print(stack[-1])
            stack.pop()
        else:
            print(-1)
    elif command == 'size':
        print(len(stack))
    elif command == 'empty':
        print(0 if len(stack) else 1)
    else:
        print(stack[-1] if len(stack) else -1)
