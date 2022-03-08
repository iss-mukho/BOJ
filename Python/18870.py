import sys

# 입력
N = int(sys.stdin.readline())
X = list(map(int, sys.stdin.readline().split()))

# 처리
X2 = sorted(list(set(X)))
x_zip = {X2[x] : x for x in range(len(X2))}

# 출력
for i in X:
    print(x_zip[i], end=' ')
