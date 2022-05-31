import sys
input = sys.stdin.readline

coins = []
N, K = tuple(map(int, input().split()))
for _ in range(N):
    coins.append(int(input()))

cnt = 0
for i in range(N-1, -1, -1):
    if K < coins[i]:
        continue
    
    cnt += K // coins[i]
    K = K % coins[i]

print(cnt)
