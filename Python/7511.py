# 백준 7511: 소셜 네트워킹 어플리케이션(골드 V), https://www.acmicpc.net/problem/7511
import sys
input = sys.stdin.readline

def findParent(x):
    if parent[x] != x:
        parent[x] = findParent(parent[x])
    return parent[x]

def unionParent(a, b):
    a = findParent(a)
    b = findParent(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

t = int(input())
for tc in range(1, t+1):
    answer = []

    n = int(input())
    k = int(input())

    parent = [i for i in range(n)]
    for _ in range(k):
        a, b = map(int, input().split())
        if findParent(a) != findParent(b):
            unionParent(a, b)
    
    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        if findParent(a) == findParent(b):
            answer.append(1)
        else:
            answer.append(0)
    
    print(f"Scenario {tc}: ")
    for ans in answer:
        print(ans)
    print()
