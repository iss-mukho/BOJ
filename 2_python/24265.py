# 백준 24265: 알고리즘 수업 - 알고리즘의 수행 시간 4(브론즈 III), https://www.acmicpc.net/problem/24265
ans = 0
for i in range(1, int(input())):
    ans += i
print("{}\n{}".format(ans, 2))
