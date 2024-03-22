numberCount = 0
stack = []
isFind = False

def back(digit):
  global numberCount, stack, isFind
  
  if len(stack) == digit:
    numberCount += 1

    if numberCount == N:
      isFind = True
      return

  for n in range(10):
    if len(stack) == 0:
      if digit > 1 and n == 0: continue
    elif n >= stack[-1]:
      break
    
    stack.append(n)
    back(digit)
    if isFind: break
    stack.pop()

def getAnswer():
  for d in range(1,11):
    back(d)
    if isFind: break
  
  return int("".join(map(str, stack))) if isFind else -1

N = int(input())
print(getAnswer())
