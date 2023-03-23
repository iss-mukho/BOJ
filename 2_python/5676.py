# 백준 5676: 음주 코딩(골드 I), https://www.acmicpc.net/problem/5676
import sys
input = sys.stdin.readline

tree = []
startIndex = 1

def reset(tree, startIndex):
    tree = []
    startIndex = 1

def convertOne(newNumber):
    if newNumber > 0:
        return 1
    elif newNumber == 0:
        return 0
    else:
        return -1

def convertNumbers():
    for i in range(N):
        numbers[i] = convertOne(numbers[i])

def init():
    global tree, startIndex

    while startIndex <= N:
        startIndex *= 2
    tree = [0 for _ in range(startIndex * 3 + 1)]
    for i in range(N):
        tree[startIndex + i] = numbers[i]
    for i in range(startIndex-1, 0, -1):
        tree[i] = tree[i*2] * tree[i*2+1]

# Special Thanks to ChatGPT
def update(index, newNumber):
    tree[index] = convertOne(newNumber)
    index //= 2
    while index > 0:
        tree[index] = tree[index * 2] * tree[index * 2 + 1]
        index //= 2
    
def getAnswer(left, right):
    ans = 1

    while left <= right:
        if left % 2 == 1:
            ans *= tree[left]
            left += 1
        if right % 2 == 0:
            ans *= tree[right]
            right -= 1
        left //= 2
        right //= 2

    if ans > 0: return '+'
    elif ans == 0: return '0'
    else: return '-'

while True:
    try:
        reset(tree, startIndex)

        N, K = map(int, input().split())
        numbers = list(map(int, input().split()))
        convertNumbers()
        init()
        
        answer = ""
        for _ in range(K):
            cmd, num1, num2 = map(str, input().split())
            num1, num2 = int(num1), int(num2)

            if cmd == 'C':
                update(startIndex + num1 - 1, num2)
            else:
                answer += getAnswer(startIndex + num1 - 1, startIndex + num2 - 1)
        print(answer)
    except Exception:
        break
