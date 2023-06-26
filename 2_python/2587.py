# 백준 2587: 대표값2(브론즈 II), https://www.acmicpc.net/problem/2587
number = []
for _ in range(5): number.append(int(input()))
number.sort()
print(sum(number) // 5, number[2], sep='\n')