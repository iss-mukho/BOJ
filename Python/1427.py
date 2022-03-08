import sys

N = sys.stdin.readline()
temp = list(N)
temp.sort(reverse=True)
N = ''.join(temp)

print(N)
