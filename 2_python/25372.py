# 백준 25372: 성택이의 은밀한 비밀번호(브론즈 V), https://www.acmicpc.net/problem/25372
for _ in range(int(input())):
    print("yes" if 6 <= len(input()) <= 9 else "no")
