# 백준 10845: 큐(실버 IV), https://www.acmicpc.net/problem/10845
import sys
input = sys.stdin.readline

queue = []

N = int(input())
for _ in range(N):
    commands = list(map(str, input().split()))
    command = commands[0]
    
    if command == 'push':
        queue.append(commands[1])
    elif command == 'pop':
        if len(queue):
            print(queue[0])
            del queue[0]
        else:
            print(-1)
    elif command == 'size':
        print(len(queue))
    elif command == 'empty':
        print(0 if len(queue) else 1)
    elif command == 'front':
        print(queue[0] if len(queue) else -1)
    else:
        print(queue[-1] if len(queue) else -1)
