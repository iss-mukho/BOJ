# 백준: 셀프 넘버(실버 V), https://www.acmicpc.net/problem/4673

checked = [0 for _ in range(10001)]
for i in range(1, 10001):
    temp = 0
    number_str = str(i)

    temp += i
    for sub in number_str:
        temp += int(sub)
    
    if temp <= 10000:
        checked[temp] = 1

for i in range(1, 10001):
    if checked[i] == 0:
        print(i)
