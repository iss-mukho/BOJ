import sys

input = sys.stdin.readline

stack = []

for _ in range(int(input())):
  line = input()

  if line[0] == 'p':
    if line[1] == 'u':
      lineList = line.split(' ')
      stack.append(int(lineList[1]))
    else:
      if len(stack) == 0:
        print(-1)
      else:
        print(stack[-1])
        stack.pop(-1)
  elif line[0] == 's':
    print(len(stack))
  elif line[0] == 'e':
    print(1 if len(stack) == 0 else 0)
  else:
    if len(stack) == 0:
        print(-1)
    else:
      print(stack[-1])
