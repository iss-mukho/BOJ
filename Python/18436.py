# 백준 18436: 수열과 쿼리 37(골드 I), https://www.acmicpc.net/problem/18436
import sys
input = sys.stdin.readline
MAX = 1000000000

tree = []
startIndex = 1

def init():
    global tree, startIndex

    while startIndex <= N:
        startIndex *= 2
    tree = [[0, 0] for _ in range(startIndex * 3 + 1)]

    for i in range(N):
        tree[startIndex + i] = [1, 0] if number[i] % 2 == 0 else [0, 1]
    for i in range(startIndex-1, 0, -1):
        tree[i] = [tree[i*2][0] + tree[i*2+1][0], tree[i*2][1] + tree[i*2+1][1]]

def update(index, newNumber):
    tree[index] = [1, 0] if newNumber % 2 == 0 else [0, 1]
    index //= 2

    while index > 0:
        tree[index] = [tree[index*2][0] + tree[index*2+1][0], tree[index*2][1] + tree[index*2+1][1]]
        index //= 2

# type: 0-짝수, 1-홀수
def getCount(left, right, type):
    count = 0

    while left <= right:
        if left % 2 == 1:
            count += tree[left][type]
        if right % 2 == 0:
            count += tree[right][type]

        left = (left + 1) // 2
        right = (right - 1) // 2

    return count

# 입력
N = int(input())
number = list(map(int, input().split()))
init()

M = int(input())
for _ in range(M):
    c, a, b = map(int, input().split())

    # 처리 및 출력
    if c == 1:
        update(startIndex + a - 1, b)
    elif c == 2:
        print(getCount(startIndex + a - 1, startIndex + b - 1, 0))
    else:
        print(getCount(startIndex + a - 1, startIndex + b - 1, 1))
