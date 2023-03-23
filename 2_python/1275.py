# 백준 1275: 커피숍2(골드 I), https://www.acmicpc.net/problem/1275
import sys
input = sys.stdin.readline

MAX = 100000
numbers = []
tree = [0 for _ in range(MAX * 3 + 1)]
startIdx = 1

def init():
    global N, startIdx

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

# 입력 1
N, Q = map(int, input().split())
numbers = list(map(int, input().split()))

# 트리 초기화
init()

# 입력 2, 출력 및 처리
for _ in range(Q):
    x, y, a, b = map(int, input().split())
    if x > y:
        x, y = y, x
    
    print(getSum(startIdx + x - 1, startIdx + y - 1))
    update(startIdx + a - 1, b - tree[startIdx + a - 1])