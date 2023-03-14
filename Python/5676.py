# 백준 5676: 음주 코딩(골드 I), https://www.acmicpc.net/problem/5676
import sys
input = sys.stdin.readline

tree = []
startIndex = 1

def init():
    global tree, startIndex

    while startIndex <= N:
        startIndex *= 2
    tree = [0 for _ in range(N * 4 + 1)]
    for i in range(N):
        tree[startIndex + i] = numbers[i]
    for i in range(startIndex-1, 0, -1):
        tree[i] = tree[i*2] * tree[i*2+1]

def update(index, newNumber):
    tree[index] = newNumber

    for i in range(startIndex-1, 0, -1):
        tree[i] = tree[i*2] * tree[i*2+1]
    
def getAnswer(left, right):
    