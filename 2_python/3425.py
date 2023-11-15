import sys

input = sys.stdin.readline

commands = []
numbers = []
stack = []

def isEmpty():
    return len(stack) == 0

def size():
    return len(stack)

def validate(num):
    return abs(num) <= 1000000000

def divValidate(num1, num2):
    if num1 > 0 and num2 > 0: return True
    if num1 < 0 and num2 < 0: return True
    return False

def inputCommands():
    commands.clear()

    while True:
        command = input()

        if command == '\n': continue
        if command[0] == 'Q': return False
        if command[0] == 'E': break
        commands.append(command)

    return True

def inputNumbers():
    numbers.clear()

    for _ in range(int(input())):
        numbers.append(int(input()))

def process():
    for command in commands:
        if command[0] == 'N': # NUM X
            number = int(command.split()[1])
            stack.append(number)
        elif command[0] == 'P': # POP
            if isEmpty():
                stack.clear()
                break
            else:
                stack.pop()
        elif command[0] == 'I': # INV
            if isEmpty():
                stack.clear()
                break
            else:
                stack[-1] = -stack[-1]
        elif command[0] == 'D':
            if command[1] == 'U': # DUP
                if isEmpty():
                    stack.clear()
                    break
                else:
                    stack.append(stack[-1])
            else: # DIV
                if size() < 2:
                    stack.clear()
                    break
                
                num1 = stack.pop()
                num2 = stack.pop()
                
                if num1 == 0:
                    stack.clear()
                    break

                num = abs(num2) // abs(num1)
                if not divValidate(num1, num2): num = -num
                stack.append(num)
        elif command[0] == 'S':
            if size() < 2:
                stack.clear()
                break
        
            if command[1] == 'W': # SWP
                stack[-2], stack[-1] = stack[-1], stack[-2]
            else: # SUB
                num1 = stack.pop()
                num2 = stack.pop()
                num = num2 - num1

                if not validate(num):
                    stack.clear()
                    break
                stack.append(num)
        elif command[0] == 'A': # ADD
            if size() < 2:
                stack.clear()
                break
            else:
                num1 = stack.pop()
                num2 = stack.pop()
                num = num1 + num2

                if not validate(num):
                    stack.clear()
                    break
                stack.append(num)
        elif command[0] == 'M':
            if size() < 2:
                stack.clear()
                break
            
            if command[1] == 'U': # MUL
                num1 = stack.pop()
                num2 = stack.pop()
                num = num1 * num2

                if not validate(num):
                    stack.clear()
                    break
                stack.append(num)
            else: # MOD
                num1 = stack.pop()
                num2 = stack.pop()

                if num1 == 0:
                    stack.clear()
                    break
                num = abs(num2) % abs(num1)
                if num2 < 0: num = -num
                stack.append(num)

while True:
    if (not inputCommands()): break
    inputNumbers()
    
    for number in numbers:
        stack.clear()
        stack.append(number)
        process()
        print(stack[0] if len(stack) == 1 else 'ERROR')
    
    print()
