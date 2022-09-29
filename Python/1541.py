# 백준, 잃어버린 괄호(실 II), https://www.acmicpc.net/problem/1541

expr = input()
minus = expr.split('-')
result = 0
for i in range(len(minus)):
    plus = minus[i].split('+')

    temp = 0
    for p in plus:
        temp += int(p)
    if i == 0:
        result += temp
    else:
        result -= temp

print(result)
