import sys 

input = sys.stdin.readline

MAX = 1000000000
COMMAND = []
NUMBER = []
GOSTACK = []

def inputCmdProcess():
    COMMAND.clear()

    while True:
        cmd = input()

        if cmd == '\n':
            print()
            continue

        if cmd[0] == 'Q':
            return False
        
        if cmd[0] == 'E':
            return True

        COMMAND.append(cmd)

def inputNumProcess():
    NUMBER.clear()

    for _ in range(int(input())):
        NUMBER.append(int(input()))
    
def cmdProcess(num):
    def possibleCheck(s):
        return s <= len(GOSTACK)
    
    def getSign(one, two):
        if one > 0 and two > 0:
            return True
        if one < 0 and two < 0:
            return True
        return False
    
    GOSTACK.clear()
    GOSTACK.append(num)
    
    for cmd in COMMAND:
        if cmd[0] == 'N':
            X = int(cmd.split()[1])
            GOSTACK.append(X)
        elif cmd[0] == 'P':
            if not possibleCheck(1):
                GOSTACK.clear()
                break

            GOSTACK.pop()
        elif cmd[0] == 'I':
            if not possibleCheck(1):
                GOSTACK.clear()
                break

            GOSTACK[-1] = -GOSTACK[-1]
        elif cmd[0] == "D":
            if cmd[1] == "U":
                if not possibleCheck(1):
                    GOSTACK.clear()
                    break
                
                GOSTACK.append(GOSTACK[-1])
            else:
                if not possibleCheck(2):
                    GOSTACK.clear()
                    break
                
                one = GOSTACK.pop()
                two = GOSTACK.pop()

                if one == 0:
                    GOSTACK.clear()
                    break
                
                result = abs(two) // abs(one)
                GOSTACK.append(result if getSign(one, two) else -result)
        elif cmd[0] == "S":
            if not possibleCheck(2):
                GOSTACK.clear()
                break

            if cmd[1] == "W":
                GOSTACK[-1], GOSTACK[-2] = GOSTACK[-2], GOSTACK[-1]
            else:
                one = GOSTACK.pop()
                two = GOSTACK.pop()

                result = two - one

                if abs(result) > MAX:
                    GOSTACK.clear()
                    break

                GOSTACK.append(result)
        elif cmd[0] == "A":
            if not possibleCheck(2):
                GOSTACK.clear()
                break
                
            one = GOSTACK.pop()
            two = GOSTACK.pop()

            result = one + two

            if abs(result) > MAX:
                GOSTACK.clear()
                break

            GOSTACK.append(result)
        elif cmd[0] == "M":
            if not possibleCheck(2):
                GOSTACK.clear()
                break
                
            one = GOSTACK.pop()
            two = GOSTACK.pop()

            if cmd[1] == "U":
                result = one * two

                if abs(result) > MAX:
                    GOSTACK.clear()
                    break

                GOSTACK.append(result)
            else:
                if one == 0:
                    GOSTACK.clear()
                    break

                result = abs(two) % abs(one)

                GOSTACK.append(result if two > 0 else -result)

while True:
    if not inputCmdProcess():
        break

    inputNumProcess()

    for num in NUMBER:
        cmdProcess(num)
        print(GOSTACK[0] if len(GOSTACK) == 1 else 'ERROR')
