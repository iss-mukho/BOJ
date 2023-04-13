# 백준 10826: 피보나치 수 4(실버 V), https://www.acmicpc.net/problem/10826
MAX = 10001
fibo = [0] * MAX
fibo[0] = 0
fibo[1] = 1

n = int(input())
for i in range(2, n+1):
    fibo[i] = fibo[i-2] + fibo[i-1]
print(fibo[n])
