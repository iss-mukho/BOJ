A = input()
B = input()
C = input()

lenA, lenB, lenC = len(A), len(B), len(C)
dp = [[[0 for _ in range(lenC + 1)] for _ in range(lenB + 1)] for _ in range(lenA + 1)]

for i in range(1, lenA + 1):
  for j in range(1, lenB + 1):
      for k in range(1, lenC + 1):
        if A[i - 1] == B[j - 1] == C[k - 1]:
          dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1
        else:
          dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1])

print(dp[lenA][lenB][lenC])
