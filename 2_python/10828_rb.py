import sys

input = sys.stdin.readline

stack = []
for _ in range(int(input())):
    command = input()
    if command[0] == "p":
        if command[1] == "u":
            number = int(command.split()[1])
            stack.append(number)
        else:
            if not len(stack):
                print(-1)
                continue
            print(stack.pop())
    elif command[0] == "s":
        print(len(stack))
    elif command[0] == "e":
        print(0 if len(stack) else 1)
    else:
        print(stack[-1] if len(stack) else -1)
