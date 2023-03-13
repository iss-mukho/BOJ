# 백준 16975: 수열과 쿼리 21(플래티넘 IV), https://www.acmicpc.net/problem/16975
# Segment Tree with Lazy Propagation(Top-bottom) 이었는데..?
import sys
input = sys.stdin.readline

lazy = []
startIndex = 1

def init():
    global lazy, startIndex

    while startIndex <= N:
        startIndex *= 2
    lazy = [0 for _ in range(startIndex * 3 + 1)]

def update(index, number):
    lazy[index] += number
    while index > 0:
        index //= 2
        lazy[index] += number

def query(right):
    ans = 0

    left = startIndex
    while left <= right:
        if left % 2 == 1:
            ans += lazy[left]
        if right % 2 == 0:
            ans += lazy[right]
        left = (left + 1) // 2
        right = (right - 1) // 2

    return ans

N = int(input())
number = list(map(int, input().split()))
init()

M = int(input())
for _ in range(M):
    inputQuery = list(map(int, input().split()))

    if inputQuery[0] == 2:
        print(number[inputQuery[1] - 1] + query(startIndex + inputQuery[1] - 1))
        continue
    update(startIndex + inputQuery[1] - 1, inputQuery[3])
    update(startIndex + inputQuery[2], -inputQuery[3])
