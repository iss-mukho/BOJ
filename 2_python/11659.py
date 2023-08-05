import sys
input = sys.stdin.readline

N, M = map(int, input().split())
numbers = list(map(int, input().split()))

acc = [0] * (N + 1)

for i in range(1, N + 1):
    acc[i] = acc[i - 1] + numbers[i - 1]

for _ in range(M):
    i, j = map(int, input().split())
    print(acc[j] - acc[i - 1])