# 백준 7578: 공장(플래티넘 V), https://www.acmicpc.net/problem/7578
import sys
input = sys.stdin.readline
MAX = 1000001

def update(start, end, index, node):
    if index < start or end < index: return
    if start == end:
        tree[node] += 1
        return
    
    update(start, (start + end) // 2, index, node * 2)
    update((start + end) // 2 + 1, end, index, node * 2 + 1)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]

def query(start, end, left, right, node):
    if end < left or right < start: return 0
    if left <= start and end <= right: return tree[node]
    return query(start, (start + end) // 2, left, right, node * 2) + query((start + end) // 2 + 1, end, left, right, node * 2 + 1)

answer = 0
N = int(input())
number = [0] * MAX
tree = [0] * (MAX * 2)

num = list(map(int, input().split()))
for i in range(N):
    number[num[i]] = i

num = list(map(int, input().split()))
for i in range(N):
    p = number[num[i]]
    answer += query(0, MAX - 1, p, MAX - 1, 1)
    update(0, MAX - 1, p, 1)

print(answer)
