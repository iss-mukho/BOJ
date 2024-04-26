N = int(input())
A = list(map(int, input().split()))
B, C = map(int, input().split())

answer = 0

for a in A:
  if a < B:
    a = 0
  else:
    a -= B

    answer += (a // C)
    if a % C != 0:
      answer += 1
  answer += 1

print(answer)
