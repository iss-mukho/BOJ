import sys
input = sys.stdin.readline

info = {}
N, M = map(int, input().split())
for _ in range(N):
    site, pw = input().split()
    info[site] = pw
for _ in range(M):
    print(info[input().rstrip()])