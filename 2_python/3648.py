# 백준 3648: 아이돌(플래티넘 III), https://www.acmicpc.net/problem/3648
import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

def SCC(node):
    global index, sccNumber
    
    visited[node] = index
    index += 1
    stack.append(node)
    root = visited[node]

    for next in graph[node]:
        if not visited[next]:
            root = min(root, SCC(next))
        elif not check[next]:
            root = min(root, visited[next])

    if root == visited[node]:
        curSCC = []
        while True:
            top = stack.pop()
            check[top] = True
            curSCC.append(top)
            CNF[top] = sccNumber
            if top == node: break
        sccNumber += 1
        sccArray.append(curSCC)

    return root

while True:
    inputLine = input()
    if inputLine == '': break

    N, M = map(int, inputLine.split())
    graph = [[] for _ in range(N * 2)]
    for _ in range(M):
        a, b = map(int, input().split())
        if a < 0: a = N - a
        if b < 0: b = N - b
        a -= 1
        b -= 1
        graph[(a + N) % (N * 2)].append(b)
        graph[(b + N) % (N * 2)].append(a)
    graph[N].append(0)

    visited = [False for _ in range(N * 2)]
    check = [False for _ in range(N * 2)]
    index = 1
    sccNumber = 0
    CNF = [-1 for _ in range(N * 2)]
    stack = []
    sccArray = []

    for i in range(N * 2):
        if not visited[i]:
            SCC(i)

    printInfo = True
    for i in range(N):
        if CNF[i] == CNF[N + i]:
            printInfo = False
            break
    print("yes" if printInfo else "no")
