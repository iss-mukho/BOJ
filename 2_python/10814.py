import sys

N = int(sys.stdin.readline())
User = []

#입력
for i in range(N):
    age, name = tuple(map(str, sys.stdin.readline().strip().split()))
    User.append([int(age), name])

# 정렬
User.sort(key=lambda u:u[0])

# 출력
for u in User:
    print(f"{u[0]} {u[1]}")
