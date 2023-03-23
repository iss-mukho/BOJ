# 백준 25304: 영수증(브론즈 V), https://www.acmicpc.net/problem/25304
import sys
input = sys.stdin.readline

X = int(input())
N = int(input())
money = 0
for _ in range(N):
    a, b = map(int, input().split())
    money += (a * b)

print("Yes" if money == X else "No")
