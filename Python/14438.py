# 백준 14438: 수열과 쿼리 17(골드 I), https://www.acmicpc.net/problem/14438
import sys
input = sys.stdin.readline

MAX = 100000000

def init():
    global startIndex, tree

    while startIndex <= N:
        startIndex *= 2
    tree = [0 for _ in range(startIndex * 3 + 1)] # 메모리 초과 방지용
    for i in range(N):
        tree[startIndex + i] = numbers[i]
    for i in range(startIndex-1, 0, -1):
        tree[i] = min(tree[i*2], tree[i*2+1])

def update(index, newNumber):
    tree[index] = newNumber
    index //= 2

    while index > 0:
        tree[index] = min(tree[index*2], tree[index*2+1])
        index //= 2

def getMin(left, right):
    ans = MAX+1
    while left <= right:
        if left % 2 == 1:
            ans = min(ans, tree[left])
        if right % 2 == 0:
            ans = min(ans, tree[right])
        left = (left + 1) // 2
        right = (right - 1) // 2
    return ans

# 입력 1
N = int(input())
numbers = list(map(int, input().split()))
tree = []
startIndex = 1

# index tree 초기화
init()

# 입력 2
M = int(input())
for _ in range(M):
    query = list(map(int, input().split()))

    # 처리
    if query[0] == 2:
        queryAnswer = getMin(startIndex + query[1] - 1, startIndex + query[2] - 1)
        print(queryAnswer)
        continue
    update(startIndex + query[1] - 1, query[2])
