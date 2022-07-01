import sys
input = sys.stdin.readline

N = int(input())
counting = [0] * 10001

for _ in range(N):
    counting[int(input())] += 1

for i in range(1, len(counting)):
    if counting[i] != 0:
        for _ in range(counting[i]):
            print(i)
