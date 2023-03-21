# 백준 1629: 곱셈(실버 I), https://www.acmicpc.net/problem/1629
A, B, C = map(int, input().split())

def check(a, b):
    if b == 1:
        return a % C
    elif b % 2 == 0:
        x = check(a, b // 2)
        return (x*x) % C
    else:
        x = check(a, (b-1) // 2)
        return (x*x) * a % C

print(check(A, B))