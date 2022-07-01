N = int(input())
numbers = list(map(int, input().split()))

answer = 0
for number in numbers:
    if number == 1:
        continue

    is_sosu = True
    for i in range(2, number//2+1):
        if number % i == 0:
            is_sosu = False
            break

    if is_sosu:
        answer += 1

print(answer)
