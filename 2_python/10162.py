# 백준 10162: 전자레인지(브론즈 III), https://www.acmicpc.net/problem/10162
T = int(input())
if T % 10 != 0:
    print(-1)
else:
    A = B = C = 0
    A = T // 300
    T %= 300
    B = T // 60
    T %= 60
    C = T // 10
    T %= 10
    print("{} {} {}".format(A, B, C))
