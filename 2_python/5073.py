import sys

input = sys.stdin.readline

while True:
  numbers = list(map(int, input().split()))
  numbers.sort()
  A, B, C = numbers

  if A == B == C:
    if not A:
      break

    print("Equilateral")
    continue

  if A + B < C:
    print("Invalid")
    continue

  if A == B or B == C or C == A:
    print("Isosceles")
  else:
    print("Scalene")
