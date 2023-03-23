# 백준 2268: 수들의 합(골드 I), https://www.acmicpc.net/problem/2268
import sys
input = sys.stdin.readline

tree = []
startIndex = 1

def init():
    global tree, startIndex
    while startIndex <= N:
        startIndex *= 2
    tree = [0 for _ in range(startIndex*2+1)]

def modify(index, diff):
    tree[index] += diff
    index //= 2

    while index > 0:
        tree[index] += diff
        index //= 2

def sum(left, right):
    ans = 0
    while left <= right:
        if left % 2 == 1:
            ans += tree[left]
        if right % 2 == 0:
            ans += tree[right]
        left = (left + 1) // 2
        right = (right - 1) // 2
    return ans

N, M = map(int, input().split())
init()

for _ in range(M):
    c, a, b = map(int, input().strip().split())
    if c == 0:
        if a > b: a, b = b, a
        print(sum(startIndex + a - 1, startIndex + b - 1))
    else:
        modify(startIndex + a - 1, b - tree[startIndex + a - 1])
