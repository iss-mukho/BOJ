# 백준 5585: 거스름돈(브론즈 II), https://www.acmicpc.net/problem/5585
coins = [500, 100, 50, 10, 5, 1]
coinCount = 0

money = 1000 - int(input())

index = 0
while money:
    coin = coins[index]

    coinCount += (money // coin)
    money %= coin
    index += 1

print(coinCount)