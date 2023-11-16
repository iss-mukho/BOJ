GRADE_DICT = {
    'A+': 4.5,
    'A0': 4.0,
    'B+': 3.5,
    'B0': 3.0,
    'C+': 2.5,
    'C0': 2.0,
    'D+': 1.5,
    'D0': 1.0,
    'F': 0.0,
}

A = []
B = 0

for _ in range(20):
    _, h, g = list(input().split())
    if g == 'P': continue

    temp = float(h)
    A.append(temp * GRADE_DICT[g])
    B += temp

print("%0.6f" % (sum(A) / B))
