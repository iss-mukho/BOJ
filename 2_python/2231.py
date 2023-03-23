N = int(input())

result = 0
for n in range(1, 1000001):
    temp = n
    for x in str(n):
        temp += int(x)
    
    if temp == N:
        result = n
        break

print(result)