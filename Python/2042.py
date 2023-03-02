# 백준 2042: 구간 합 구하기(골드 V), https://www.acmicpc.net/problem/2042
import sys
input = sys.stdin.readline

MAX = 1000000
numbers = []
tree = [0 for _ in range(MAX * 3 + 1)]
startIdx = 1

def init():
    global startIdx

    while startIdx <= N:
        startIdx *= 2
    for i in range(N):
        tree[startIdx + i] = numbers[i]
    for i in range(startIdx-1, 0, -1):
        tree[i] = tree[i*2] + tree[i*2+1]

def update(idx, diff):
    while idx > 0:
        tree[idx] += diff
        idx //= 2

def getSum(left, right):
    ans = 0
    while left <= right:
        if left % 2 == 1:
            ans += tree[left]
        if right % 2 == 0:
            ans += tree[right]
        left = (left + 1) // 2
        right = (right - 1) // 2
    return ans

N, M, K = map(int, input().split())

for _ in range(N):
    numbers.append(int(input()))

init()

for _ in range(M + K):
    a, b, c = map(int, input().split())

    if a == 1:
        update(startIdx + b - 1, c - tree[startIdx + b - 1])
    else:
        print(getSum(startIdx + b - 1, startIdx + c - 1))