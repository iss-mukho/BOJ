A = input()
B = input()

lenA, lenB = len(A), len(B)
dp = [[0 for _ in range(lenB + 1)] for _ in range(lenA + 1)]

# LCS: Longest Common Subsequence(Substring)
for i in range(1, lenA + 1):
  for j in range(1, lenB + 1):
    if A[i - 1] == B[j - 1]:
      dp[i][j] = dp[i - 1][j - 1] + 1
    else:
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

print(dp[lenA][lenB])
