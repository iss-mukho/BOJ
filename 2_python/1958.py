A = input()
B = input()

lenA, lenB = len(A), len(B)
dp = [[[0, ''] for _ in range(lenB + 1)] for _ in range(lenA + 1)]

for i in range(1, lenA + 1):
  for j in range(1, lenB + 1):
      if A[i - 1] == B[j - 1]:
        dp[i][j][0] = dp[i - 1][j - 1][0] + 1
        dp[i][j][1] = dp[i - 1][j - 1][1] + A[i - 1]
      else:
        if dp[i - 1][j][0] > dp[i][j - 1][0]:
          dp[i][j] = dp[i - 1][j]
        else:
          dp[i][j] = dp[i][j - 1]

print(dp[lenA][lenB][0])
if dp[lenA][lenB][0]:
  print(dp[lenA][lenB][1])
