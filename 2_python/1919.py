x = list(input())
y = list(input())

answer = len(x) + len(y)

for i in range(len(x)):
    for j in range(len(y)):
        if x[i] == y[j]:
            x[i], y[j] = -1, -2
            answer -= 2

print(answer)
