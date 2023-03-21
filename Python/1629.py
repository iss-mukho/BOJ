# 백준 1629: 곱셈(실버 I), https://www.acmicpc.net/problem/1629
A, B, C = map(int, input().split())

if A % 2 == 0:
    print(A % C)
else: print(A*A % C)