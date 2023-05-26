# 백준 14725: 개미굴(골드 III), https://www.acmicpc.net/problem/14725
import sys
input = sys.stdin.readline

def answer(target, depth):
    key = sorted(target.keys())
    for k in key:
        print("--" * depth + k)
        answer(target[k], depth + 1)

N = int(input())
ant = {}

for _ in range(N):
    robot = list(input().split())
    target = ant
    for name in robot[1:]:
        if name not in target:
            target[name] = {}
        target = target[name]

answer(ant, 0)
