# 백준 5076: Web Pages(골드 IV), https://www.acmicpc.net/problem/5076
import sys
input = sys.stdin.readline

while True:
    line = input().strip()
    if line == '#': break

    stack = []
    i = -1
    while i < len(line):
        i += 1
        if i == len(line): break
        if(line[i] != '<'): continue

        strStart = i+1
        strEnd = 0
        while line[i] != '>':
            i += 1
            strEnd += 1

        tag = line[strStart:strStart+strEnd-1]
        convert = tag.split()
        if convert[-1] == '/': continue
        if convert[0][0] == '/':
            if len(stack) != 0 and stack[-1] == convert[0][1:len(convert[0])]: stack.pop()
            elif len(stack) == 0: stack.append(convert[0])
        else:
            stack.append(convert[0])

    print('illegal' if len(stack) else 'legal')
