# 백준 20254: Site Score(브론즈 V), https://www.acmicpc.net/problem/20254
scores = list(map(int, input().split()))
print(scores[0]*56 + scores[1]*24 + scores[2]*14 + scores[3]*6)