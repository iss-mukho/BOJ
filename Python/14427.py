# 백준 14427: 수열과 쿼리 15(골드 II), https://www.acmicpc.net/problem/14427
import sys
input = sys.stdin.readline

MAX = 1000000000
INDEX_MAX = 100000

def init():
    global startIndex, tree

    while startIndex <= N:
        startIndex *= 2
    tree = [[MAX, INDEX_MAX+1] for _ in range(startIndex * 3 + 1)] # 메모리 초과 방지용
    for i in range(N):
        tree[startIndex + i] = [numbers[i], i+1]
    for i in range(startIndex-1, 0, -1):
        if tree[i*2] < tree[i*2+1]:
            tree[i] = tree[i*2][:]
        else:
            tree[i] = tree[i*2+1][:]

def update(index, newNumber):
    tree[index][0] = newNumber
    index //= 2

    while index > 0:
        tree[index] = min(tree[index*2][:], tree[index*2+1][:])
        index //= 2

# 입력 1
N = int(input())
numbers = list(map(int, input().split()))
tree = [] # [number, index]
startIndex = 1

# index tree 초기화
init()

# 입력 2
M = int(input())
for _ in range(M):
    query = list(map(int, input().split()))

    # 처리
    if query[0] == 2:
        print(tree[1][1])
        continue
    update(startIndex + query[1] - 1, query[2])
