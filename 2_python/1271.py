# 백준 1271: 엄청난 부자2(브론즈 V), https://www.acmicpc.net/problem/1271
n, m = map(int, input().split())
print("{}\n{}".format(n//m, n%m))