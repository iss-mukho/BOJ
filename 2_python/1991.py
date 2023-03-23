# 백준 1991: 트리 순회(실버 I), https://www.acmicpc.net/problem/1991
import sys
input = sys.stdin.readline

def preOrder(idx):
    if idx == -1:
        return
    print(chr(idx + 65), end='')
    preOrder(tree[idx][0])
    preOrder(tree[idx][1])

def inOrder(idx):
    if idx == -1:
        return
    inOrder(tree[idx][0])
    print(chr(idx + 65), end='')
    inOrder(tree[idx][1])

def postOrder(idx):
    if idx == -1:
        return
    postOrder(tree[idx][0])
    postOrder(tree[idx][1])
    print(chr(idx + 65), end='')

N = int(input())
tree = [[-1, -1] for _ in range(26)]

for i in range(1, N+1):
    P, L, R = map(str, input().split())
    
    p = ord(P) - 65
    l = ord(L) - 65
    r = ord(R) - 65

    tree[p][0] = l if L != '.' else -1
    tree[p][1] = r if R != '.' else -1

preOrder(0)
print()
inOrder(0)
print()
postOrder(0)
print()
