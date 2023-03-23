# 백준 2480: 주사위 세개(브론즈 IV), https://www.acmicpc.net/problem/2480
import sys
input = sys.stdin.readline

maxCountNumber = 0
maxNumber = 0
count = [0] * 7

number = list(map(int, input().split()))
for num in number:
    count[num] += 1

    if count[maxCountNumber] < count[num]:
       maxCountNumber = num
    maxNumber = max(maxNumber, num)

if count[maxCountNumber] == 3:
    print(10000 + maxCountNumber * 1000)
elif count[maxCountNumber] == 2:
    print(1000 + maxCountNumber * 100)
else:
    print(maxNumber * 100)
