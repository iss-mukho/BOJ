# 백준 10813: 공 바꾸기(브론즈 II), https://www.acmicpc.net/problem/10813
N, M = map(int, input().split())
numbers = [i for i in range(1, N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    numbers[a-1], numbers[b-1] = numbers[b-1], numbers[a-1]
print(*numbers)