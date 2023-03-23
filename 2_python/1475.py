# 백준, 방 번호(실 V), https://www.acmicpc.net/problem/1475

N = input()
numbers = [0 for _ in range(10)]

for n in N:
    numbers[int(n)] += 1

min_num = -1
max_num = -1
if numbers[6] < numbers[9]:
    min_num = 6
    max_num = 9
else:
    min_num = 9
    max_num = 6

while numbers[max_num] - numbers[min_num] > 1:
    numbers[max_num] -= 1
    numbers[min_num] += 1

print(max(numbers))
