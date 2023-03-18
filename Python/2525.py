# 백준 2525: 오븐 시계(브론즈 III), https://www.acmicpc.net/problem/2525
import sys
input = sys.stdin.readline

hour, minute = map(int, input().split())
addTime = int(input())

minute += addTime
hour += (minute // 60)
minute %= 60
hour %= 24

print(str(hour) + ' ' + str(minute))