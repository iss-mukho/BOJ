# 백준 19532: 수학은 비대면강의입니다(브론즈 II), https://www.acmicpc.net/problem/19532
a, b, c, d, e, f = map(int, input().split())
x = (c * e - b * f) // (a * e - b * d)
y = (c * d - a * f) // (b * d - a * e)
print(x, y)