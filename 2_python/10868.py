# 백준 10868: 최솟값(골드 I), https://www.acmicpc.net/problem/10868
import sys
input = sys.stdin.readline

INF = 1000000001

tree = []
startIndex = 1

def init():
    global tree, startIndex
    while startIndex <= N:
        startIndex *= 2
    tree = [INF for _ in range(startIndex*2+1)]
    for i in range(N):
        tree[startIndex + i] = numbers[i]
    for i in range(startIndex-1, 0, -1):
        tree[i] = min(tree[i*2], tree[i*2+1])

def getMinNumber(left, right):
    ans = INF
    while left <= right:
        if left % 2 == 1:
            ans = min(ans, tree[left])
        if right % 2 == 0:
            ans = min(ans, tree[right])
        left = (left + 1) // 2
        right = (right - 1) // 2
    return ans

N, M = map(int, input().split())
numbers = []
for _ in range(N):
    numbers.append(int(input()))
init()

for _ in range(M):
    S, E = map(int, input().split())
    print(getMinNumber(startIndex + S - 1, startIndex + E - 1))
