import sys
input = sys.stdin.readline

N, K = map(int, input().split())
coins = []
for _ in range(N):
    coins.append(int(input()))
coins.sort(reverse=True)

answer = 0
for coin in coins:
    if K == 0:
        break
    answer += K // coin
    K %= coin
    
print(answer)