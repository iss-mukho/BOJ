# 백준 11505: 구간 곱 구하기(골드 I), https://www.acmicpc.net/problem/11505
import sys
input = sys.stdin.readline
INF = 1000000007

number = []
tree = []
startIndex = 1

def init():
    global startIndex, tree, number
    
    while startIndex <= N:
        startIndex *= 2
    tree = [1] * (startIndex*2)

    for i in range(N):
        tree[startIndex + i] = number[i]
        
    for i in range(startIndex-1, 0, -1):
        tree[i] = (tree[i*2] * tree[i*2+1]) % INF
        
def update(index, num):
    tree[index] = num
    index //= 2
    
    while index > 0:
        tree[index] = (tree[index*2] * tree[index*2+1]) % INF
        index //= 2
    
def getMul(left, right):
    ans = 1
    
    while left <= right:
        if left % 2 == 1:
            ans = (ans * tree[left]) % INF
        if right % 2 == 0:
            ans = (ans * tree[right]) % INF
        left = (left+1) // 2
        right = (right-1) // 2
    
    return ans

N, M, K = map(int, input().split())
for _ in range(N):
    number.append(int(input()))
    
init()
for _ in range(M+K):
    a, b, c = map(int, input().split())
    
    if a == 1:
        update(startIndex + b - 1, c)
    else:
        print(getMul(startIndex + b - 1, startIndex + c - 1))
    
