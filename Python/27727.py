n = int(input())
a = list(map(int, input().split()))
k = int(input())

x = min(a)
p = a.count(x)
a = [ai - x for ai in a]
res = 0

while True:
    if k < p:
        break
    k -= p
    res += 1
    y = min(ai for ai in a if ai != 0)
    q, r = divmod(k, p * (y - x))
    res += q
    k = r
    x += q
    a = [ai - q * p if ai == x else ai for ai in a]
    p = a.count(x)

print(res if res > 0 else 0)
