# 백준 1075: 나누기(브론즈 II), https://www.acmicpc.net/problem/1075
N = int(input())
F = int(input())
N = int(N / 100) * 100
i = 0
while True:
    num = N + i
    if num % F != 0:
        i += 1
        continue
    ans = int(num % 100)
    print(ans if ans > 9 else '0' + str(ans))
    break