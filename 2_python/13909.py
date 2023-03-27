# 백준 13909: 창문 닫기(실버 V), https://www.acmicpc.net/problem/13909
N = int(input())
answer = 1
while True:
    if (answer+1) ** 2 > N:
        break
    answer += 1
print(answer)
