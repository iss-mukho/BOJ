# 백준 2738: 행렬 덧셈(브론즈 V), https://www.acmicpc.net/problem/2738
N, M = map(int, input().split())
A = []
B = []

for _ in range(N):
    A.append(list(map(int, input().split())))
for _ in range(N):
    B.append(list(map(int, input().split())))
for i in range(N):
    for j in range(M):
        print(A[i][j] + B[i][j], end=' ')
    print()