# 백준 11689: GCD(n, k) = 1(골드 I), https://www.acmicpc.net/problem/11689
n = int(input())
e = n
p = 2
while p * p <= n:
    if n % p == 0: e = e // p * (p - 1)
    while n % p == 0: n //= p
    p += 1
print(e if n == 1 else e // n * (n - 1))
