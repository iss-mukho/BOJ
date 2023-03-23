import sys
input = sys.stdin.readline

numbers = list()
temp = list()

def calc(cnt, d):
    if cnt == d:
        temp_ = temp[:]
        temp_.sort(reverse=True)
        temp_str = "".join(map(str, temp_))
        numbers.append(int(temp_str))
        return

    for i in range(10):
        if i not in temp:
            if len(temp) == 0 or i > temp[-1]:
                temp.append(i)
                calc(cnt+1, d)
                temp.pop()

N = int(input())
for d in range(1, 11):
    calc(0, d)

numbers.sort()
try:
    print(numbers[N])
except:
    print(-1)