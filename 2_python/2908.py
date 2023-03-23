a, b = input().split()
a_ = int(a[::-1])
b_ = int(b[::-1])

print(a_ if a_>b_ else b_)