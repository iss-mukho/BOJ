# 백준 15990: 1, 2, 3 더하기 5(실버 II), https://www.acmicpc.net/problem/15990
import sys
input = sys.stdin.readline

INF = 1000000009
MAX = 100001

dp = [[0 for _ in range(4)] for _ in range(MAX)]
dp[1] = [0, 1, 0, 0]
dp[2] = [0, 0, 1 ,0]
dp[3] = [0, 1, 1, 1]

# 점화식 설명: https://velog.io/@jkh9615/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B0%B1%EC%A4%80-15990-1-2-3-%EB%8D%94%ED%95%98%EA%B8%B0-5-Java
for i in range(4, MAX):
    dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % INF # i번째 수를 만들때, 1로 끝나는 수
    dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % INF # 2로 끝나는 수
    dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % INF # 3으로 끝나는 수

T = int(input())
for _ in range(T):
    N = int(input())
    print(sum(dp[N]) % INF)
    