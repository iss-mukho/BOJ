# 백준: 나무 자르기(실버 II), https://www.acmicpc.net/problem/2805
import sys
input = sys.stdin.readline

def calc(trees, start, end, M):
    while start <= end:
        mid = (start + end) // 2
        temp_h = cutting(trees, mid)

        if temp_h >= M:
            start = mid + 1
        else:
            end = mid - 1
    
    return end

def cutting(trees, h):
    result = 0
    for tree in trees:
        if h < tree:
            result += (tree - h)
    return result

N, M = map(int, input().split())
trees = list(map(int, input().split()))
print(calc(trees, 0, max(trees), M))
