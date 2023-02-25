IPv6 = list(map(str, input().split(':')))
temp = []

for i in range(len(IPv6)):
    l = len(IPv6[i])

    if l == 0:
        temp.append(i)
        continue
    if l < 4:
        IPv6[i] = "0" * (4-l) + IPv6[i]

if temp:
    for _ in temp:
        del IPv6[temp[0]]
    while len(IPv6) != 8:
        IPv6.insert(temp[0], "0000")

print(":".join(IPv6))