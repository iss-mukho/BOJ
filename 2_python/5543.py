# 백준 5543: 상근날드(브론즈 IV), https://www.acmicpc.net/problem/5543
burgers = []
drinks = []

for _ in range(3):
    burgers.append(int(input()))
burgers.sort()

for _ in range(2):
    drinks.append(int(input()))
drinks.sort()

print(burgers[0] + drinks[0] - 50)