# 백준 21300: Bottle Return(브론즈 V), https://www.acmicpc.net/problem/21300
num = list(map(int, input().split()))
ans = 0
for n in num:
    ans += n
print(ans * 5)