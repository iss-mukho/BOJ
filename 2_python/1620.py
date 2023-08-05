import sys
input = sys.stdin.readline

N, M = map(int, input().split())

idx = 0
dict = {}

for _ in range(N):
    pocketmon = input().rstrip()
    idx += 1
    dict[pocketmon] = str(idx)
    dict[str(idx)] = pocketmon

for _ in range(M):
    f = input().rstrip()
    print(dict[f])