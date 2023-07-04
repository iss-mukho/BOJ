# 백준 5554: 심부름 가는 길(브론즈 IV), https://www.acmicpc.net/problem/5554
time = 0
for _ in range(4): time += int(input())
print(time // 60)
print(time % 60)
